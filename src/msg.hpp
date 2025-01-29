#ifndef MSG_HPP
#include <nlohmann/json.hpp>
#include <string>
#include "ws_client.hpp"

using nlohmann::json;
using std::string;

// Handle
void handle(const std::string& msg,MyWebSocketClient* ws);

// 处理 私聊/群聊 消息，再判断消息是否为命令，
// 是命令就传递给commamd函数
#define MSG_HPP
#endif
