#include "plugin_api.hpp"

using std::string;
using std::map;
class introduce : public BotPluginApi{
    void init(std::map<std::string,boost::shared_ptr<BotPluginApi>>* _plugins) override {
        this-> commandToDescr["自我介绍"] = "自我介绍";
        this-> name = "introduce";
        this-> plugins = _plugins;
        (*plugins)["exec_command"] -> import(this-> name);
    }
    string execute(string command) override {
        return "咱是帕酱喵，是来自萌国的猫娘";
    }
    
};
extern "C" BOOST_SYMBOL_EXPORT introduce plugin;
introduce plugin;
