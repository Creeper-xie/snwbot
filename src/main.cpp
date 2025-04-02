#include <toml++/toml.hpp>
#include <boost/filesystem.hpp>
#include <boost/dll/runtime_symbol_info.hpp>

#include "bot.hpp"

namespace fs = boost::filesystem;
namespace sys = boost::system;

fs::path plugin_dir() {
    const fs::path executable_dir = boost::dll::program_location().parent_path();
    const fs::path plugin_dir = executable_dir / "plugins";
    // 刻意忽略错误处理，让程序在遇到错误时停止运行
    return fs::canonical(plugin_dir);
}

int main(int argc, char** argv) {
  try {
    const toml::table config = toml::parse_file("config.toml");
    const std::string url = *config["bot"]["ws_url"].value<std::string>();
    const std::string token = *config["bot"]["token"].value<std::string>();
    Bot bot(NULL);
    bot.connect(url.data(),token);

    const fs::path plugins_dir = plugin_dir();
    for (auto &entry : fs::directory_iterator(plugins_dir)) {
        if(fs::is_regular_file(entry)){
            bot.load_plugin(entry);
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
