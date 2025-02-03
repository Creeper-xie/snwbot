#include <boost/dll/import.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <map>

#include "plugin_api.hpp"

namespace dll = boost::dll;
namespace fs = boost::filesystem;

using apiPtr = boost::shared_ptr<BotPluginApi>;
void loadPlugin(std::map<std::string,apiPtr>& plugins,map<string,string>& commands,const fs::path& path){
    auto plugin = boost::dll::import_symbol<BotPluginApi>(path,"plugin",dll::load_mode::append_decorations);
    plugins[plugin->name] = std::move(plugin);
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
