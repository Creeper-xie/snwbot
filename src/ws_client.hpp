#ifndef WS_CLIENT_HPP

#include <hv/WebSocketClient.h>

using namespace hv;

class BotWebSocketClient : public WebSocketClient {
public:
    
    BotWebSocketClient(EventLoopPtr loop = NULL); 
    ~BotWebSocketClient();

    int connect(const char* url,std::string token) ;
};

#define WS_CLIENT_HPP
#endif
