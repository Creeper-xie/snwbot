#include "plugin_api.hpp"

using std::string;
using std::map;
class introduce : public BotPluginApi{
    void init(Bot& bot) override {
        commands.push_back("自我介绍");
        name = "introduce";
    }
    string execute(string command) override {
        return "咱是帕酱喵，是来自萌国的猫娘";
    }
    
};
extern "C" BOOST_SYMBOL_EXPORT introduce plugin;
introduce plugin;
