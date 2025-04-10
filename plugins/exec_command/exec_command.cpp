#include <string>

#include "plugin_api.hpp"

using std::string;

class exec_command : public BotPluginApi{
    void init(std::map<std::string,boost::shared_ptr<BotPluginApi>>* _plugins) override {
        this-> plugins = _plugins;
    }
    string execute(const string& str) override{
        
        if(this->commands.contains(command)){
            return ((this->plugins)[(this->commands)[command]] -> execute(command));
        }
        return string("");
    }
    void import(pluginName) override {
        
    }
}
extern "C" BOOST_SYMBOL_EXPORT exec_command plugin;
exec_command plugin;

