#include <boost/dll/import.hpp>
#include <boost/filesystem.hpp>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <map>

#include "plugin_manage.hpp"
#include "plugin_api.hpp"

namespace dll = boost::dll;
namespace fs = boost::filesystem;

using apiPtr = boost::shared_ptr<BotPluginApi>;
void load_plugin(std::map<std::string,apiPtr>& plugins,map<string,string>& commands,const fs::path& path,Bot& bot){
    auto plugin = boost::dll::import_symbol<BotPluginApi>(path,"plugin",dll::load_mode::append_decorations);
    std::function<void(string)> _send = [&bot](string str){bot.send(str);};
    plugin->init(&_send,&plugins);
    string name = plugin -> name;
    cout << "加载插件：" << name <<std::endl;
    for(string command : plugin -> commands){
        cout << "plugin_command:" << command << std::endl;
        commands[command] = name;
    }
    plugins[name] = std::move(plugin);
    };
/**
int main(int argc, char* argv[]) {
    std::map<std::string,apiPtr> plugins;
    fs::path plugins_dir = "plugins";
    for (auto entry : fs::directory_iterator(plugins_dir)){
        if(fs::is_regular_file(entry)){
            loadPlugin(plugins,entry);
            }
        }
    for (const auto& [key,value]: plugins){
        std::cout << key << std::endl;
    }
}
**/
