#ifndef MSG_CPP
#include <cstdint>
#include <string>
#include <nlohmann/json.hpp>

#include "msg.hpp"
#include "ws_client.hpp"
#include "command.hpp"

using nlohmann::json;
using std::string;
void handle(const string& msg,BotWebSocketClient* ws){
    json jsonMsg = json::parse(std::move(msg));
    if(jsonMsg.contains("post_type") && jsonMsg["post_type"].get<string>()=="message"){
        string msgData = jsonMsg["raw_message"].get<string>();
    if(msgData.empty() || !(msgData.at(0) == '>')) return;
        string::size_type n = msgData.find(' ');
        string result = command(msgData.substr(1,n-1),msgData.substr(n+1));
        if (result.empty()) return;
        json sendMsg;
        sendMsg["action"] = "send_msg";
        if(jsonMsg["message_type"].get<string>() == "private"){
            sendMsg["params"]["detail_type"] = "private";
            sendMsg["params"]["user_id"] = jsonMsg["user_id"].get<uint64_t>();
            } else if(jsonMsg["message_type"].get<string>() == "group"){
            sendMsg["params"]["detail_type"] = "group";
            sendMsg["params"]["group_id"] = jsonMsg["group_id"].get<uint64_t>();
            }
        sendMsg["params"]["message"][0]["type"] = "text";
        sendMsg["params"]["message"][0]["data"]["text"] = result;
        string str=sendMsg.dump();
        printf("%s\n",str.data());
        ws-> send(str);
        }
    };
#define MSG_CPP
#endif
