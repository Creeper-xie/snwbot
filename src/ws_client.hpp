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
    std::map<std::string,std::string>* commands;
    std::map<string,BotPluginApi>* plugins;
};

#endif
