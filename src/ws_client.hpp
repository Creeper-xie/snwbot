#ifndef WS_CLIENT_HPP
#define WS_CLIENT_HPP

#include <hv/WebSocketClient.h>
#include <map>
#include <string>

#include "plugin_api.hpp"

using apiPtr = boost::shared_ptr<BotPluginApi>;
class BotWebSocketClient : public hv::WebSocketClient {
public:
    
    BotWebSocketClient(hv::EventLoopPtr loop = NULL); 
    ~BotWebSocketClient();

    int connect(const char* url,std::string token);
    void handle(const std::string& msg,BotWebSocketClient* ws);
string command(const string& command,const string& arg,map<string,apiPtr>* plugins,map<string,string>* commands);
    std::map<std::string,std::string>* commands;
    std::map<string,apiPtr>* plugins;
};

#endif
