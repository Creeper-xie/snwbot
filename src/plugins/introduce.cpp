#include "plugin_api.hpp"

class introduce : public BotPluginApi{
    void init(std::function<void (string)> *send, map<string, boost::shared_ptr<BotPluginApi>> *plugins) override {
        commands.push_back("自我介绍");
    }
    string execute(string command) override {
        return "咱是帕酱喵，是来自萌国的猫娘";
    }
    
};
extern "C" BOOST_SYMBOL_EXPORT introduce plugin;
introduce plugin;
