#ifndef BOT_HPP
#define BOT_HPP

#include <hv/WebSocketClient.h>
#include <nlohmann/json.hpp>
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
std::string command(const std::string& command,const std::string& arg,std::map<std::string,apiPtr>* plugins,std::map<std::string,std::string>* commands);
    void send_msg(nlohmann::json& reqMsg);
    std::map<std::string,std::string>* commands;
    std::map<std::string,apiPtr>* plugins;
};

#endif
