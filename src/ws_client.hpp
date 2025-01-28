#ifndef WS_CLIENT_HPP

#include <hv/WebSocketClient.h>

using namespace hv;

class MyWebSocketClient : public WebSocketClient {
public:
    
    MyWebSocketClient(EventLoopPtr loop); 
    ~MyWebSocketClient();

    int connect(const char* url,std::string token) ;
};

#define WS_CLIENT_HPP
#endif
