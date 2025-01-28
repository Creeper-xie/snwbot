#ifndef MSG_HPP
#include <functional>
#include <string>
#include "ws_client.hpp"

void handle(const std::string& msg,const MyWebSocketClient* ws);
void privateMsg();
void groupMsg();

#define MSG_HPP
#endif
