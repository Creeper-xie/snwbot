#ifndef MSG_CPP
#include <string>
#include <nlohmann/json.hpp>

#include "msg.hpp"
#include "ws_client.hpp"
#include "command.hpp"

using nlohmann::json;
using std::string;
void handle(string& msg,MyWebSocketClient* ws){
    json jsonMsg = json::parse(std::move(msg));
    string msgType = jsonMsg["message_type"].get<string>();
    if (msgType=="private"){
        ws-> send(privateMsg(jsonMsg));
        }
    else if (msgType=="group"){
        ws-> send(groupMsg(jsonMsg));
        }
    };
string privateMsg(json& jsonMsg){};
string groupMsg(json& jsonMsg){};
#define MSG_CPP
#endif
