#include <iostream>
#include <optional>
#include <string_view>
#include <toml++/toml.hpp>
#include <string>
#include <vector>

#include "ws_client.hpp"



int main(int argc, char** argv) {
  try {
    const toml::table config = toml::parse_file("config.toml");
    const std::string url = *config["bot"]["ws_url"].value<std::string>();
    const std::string token = *config["bot"]["token"].value<std::string>();
    MyWebSocketClient ws(NULL);
    ws.connect(url.data(),token);

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
