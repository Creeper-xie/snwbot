#include <iostream>
#include <ostream>
#include <string>
#include <toml++/toml.hpp>
#include <boost/filesystem.hpp>
#include <boost/dll/runtime_symbol_info.hpp>

#include "bot.hpp"

namespace fs = boost::filesystem;
namespace sys = boost::system;

using std::string;

string config_path;

int main(int argc, char** argv) {
  try {
    if ( argc == 3 && string(argv[1]) == "-c"){
        config_path = argv[2];
    } else {
        config_path = "snwbot_config.toml";
    }
    const toml::table config = toml::parse_file(config_path);
    Bot bot;

    const fs::path plugins_dir = *config["plugins_dir"].value<std::string>();
    for (auto &entry : fs::directory_iterator(plugins_dir)) {
        if(fs::is_regular_file(entry)){
            bot.load_plugin(entry);
        }
    }

    string str;
    while (std::getline(std::cin, str)) {
            if (bot.plugins.contains("exec_command")){
                std::cout << bot.plugins["exec_command"] -> execute(str) << std::endl;
            }
        }
    
    } catch (const toml::parse_error& err) {
        std::cerr << err << std::endl;
    }

    return 0;
}
