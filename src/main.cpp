#include <toml++/toml.hpp>

#include "plugin_manage.hpp"
#include "bot.hpp"

int main(int argc, char** argv) {
  try {
    const toml::table config = toml::parse_file("config.toml");
    const std::string url = *config["bot"]["ws_url"].value<std::string>();
    const std::string token = *config["bot"]["token"].value<std::string>();
    Bot bot(NULL);
    bot.connect(url.data(),token);
    map<std::string,apiPtr> plugins;
    map<string,string> commands;
    bot.commands = &commands;
    bot.plugins = &plugins;
    fs::path plugins_dir = "plugins";
    for (auto entry : fs::directory_iterator(plugins_dir)){
        if(fs::is_regular_file(entry)){
            load_plugin(plugins,commands,entry,bot);
            }
    }
    std::string str;
    while (std::getline(std::cin, str)) {
        if (str == "close") {
            bot.close();
        } else if (str == "open") {
            bot.connect(url.data(),token);
        } else if (str == "stop") {
            bot.stop();
            break;
        } else {
            if (!bot.isConnected()) break;
            bot.send(str);
        }
    }
    } catch (const toml::parse_error& err) {
        std::cerr << err << std::endl;
    }

    return 0;
}
