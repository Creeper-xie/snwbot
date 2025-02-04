#include <toml++/toml.hpp>

#include "plugin_manage.hpp"
#include "ws_client.hpp"

int main(int argc, char** argv) {
  try {
    const toml::table config = toml::parse_file("config.toml");
    const std::string url = *config["bot"]["ws_url"].value<std::string>();
    const std::string token = *config["bot"]["token"].value<std::string>();
    BotWebSocketClient ws(NULL);
    ws.connect(url.data(),token);
    map<std::string,apiPtr> plugins;
    map<string,string> commands;
    ws.commands = &commands;
    ws.plugins = &plugins;
    fs::path plugins_dir = "plugins";
    for (auto entry : fs::directory_iterator(plugins_dir)){
        if(fs::is_regular_file(entry)){
            loadPlugin(plugins,commands,entry,ws);
            }
    }
    std::string str;
    while (std::getline(std::cin, str)) {
        if (str == "close") {
            ws.close();
        } else if (str == "open") {
            ws.connect(url.data(),token);
        } else if (str == "stop") {
            ws.stop();
            break;
        } else {
            if (!ws.isConnected()) break;
            ws.send(str);
        }
    }
    } catch (const toml::parse_error& err) {
        std::cerr << err << std::endl;
    }

    return 0;
}
