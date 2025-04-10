#ifndef BOT_CPP

#include <nlohmann/json.hpp>
#include <toml++/toml.hpp>

#include "bot.hpp"

namespace dll = boost::dll;
namespace fs = boost::filesystem;

using json = nlohmann::json;
using std::string;
using std::map;
using std::cout;

void Bot::load_plugin(const fs::path& path){
    auto plugin = boost::dll::import_symbol<BotPluginApi>(path,"plugin",dll::load_mode::append_decorations);
    plugin->init(&(this-> plugins));
    string name = plugin -> name;
    cout << "加载插件：" << name <<std::endl;
    plugins[name] = std::move(plugin);
    };


#define BOT_CPP
#endif
