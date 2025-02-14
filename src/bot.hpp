#ifndef BOT_HPP
#define BOT_HPP

#include <hv/WebSocketClient.h>
#include <map>
#include <string>

#include "plugin_api.hpp"

using apiPtr = boost::shared_ptr<BotPluginApi>;
class Bot : public hv::WebSocketClient {
public:
    
    Bot(hv::EventLoopPtr loop = NULL); 
    ~Bot();

    int connect(const char* url,std::string token);
    void handle(const std::string& msg);
string command(const string& command,const string& arg,map<string,apiPtr>* plugins,map<string,string>* commands);
    std::map<std::string,std::string>* commands;
    std::map<string,apiPtr>* plugins;
};

#endif
