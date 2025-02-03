#ifndef WS_CLIENT_CPP

#include <hv/WebSocketClient.h>
#include <nlohmann/json.hpp>
#include <toml++/toml.hpp>

#include "ws_client.hpp"
#include "msg.hpp"

using namespace hv;

BotWebSocketClient::MyWebSocketClient(EventLoopPtr loop) : WebSocketClient(loop) {}
BotWebSocketClient::~BotWebSocketClient() {}

int BotWebSocketClient::connect(const char* url,std::string token) {
        // set callbacks
        onopen = [this]() {
            const HttpResponsePtr& resp = getHttpResponse();
            printf("onopen\n%s\n", resp->body.c_str());
        };
        onmessage = [this](const std::string& msg) {
            printf("onmessage(type=%s len=%d): %.*s\n", opcode() == WS_OPCODE_TEXT ? "text" : "binary",
                (int)msg.size(), (int)msg.size(), msg.data());
                handle(msg,this);
        };
        onclose = []() {
            printf("onclose\n");
        };

        // ping
        setPingInterval(10000);

        // reconnect: 1,2,4,8,10,10,10...
        reconn_setting_t reconn;
        reconn_setting_init(&reconn);
        reconn.min_delay = 1000;
        reconn.max_delay = 10000;
        reconn.delay_policy = 2;
        setReconnect(&reconn);

        http_headers headers;
        headers["Authorization"] = "Bearer " + token;
        return open(url, headers);
    };


#define WS_CLIENT_CPP
#endif
