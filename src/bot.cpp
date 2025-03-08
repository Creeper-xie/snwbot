#ifndef BOT_CPP

#include <hv/WebSocketClient.h>
#include <nlohmann/json.hpp>
#include <toml++/toml.hpp>

#include "bot.hpp"

using json = nlohmann::json;
using std::string;
using std::map;
using std::cout;
Bot::Bot(hv::EventLoopPtr loop) : WebSocketClient(loop) {}
Bot::~Bot() {}

int Bot::connect(const char* url,std::string token) {

        // set callbacks
        onopen = [this]() {
            const HttpResponsePtr& resp = getHttpResponse();
            printf("onopen\n%s\n", resp->body.c_str());
        };
        onmessage = [this](const std::string& msg) {
            printf("onmessage(type=%s len=%d): %.*s\n", opcode() == WS_OPCODE_TEXT ? "text" : "binary",
                (int)msg.size(), (int)msg.size(), msg.data());
                handle(msg);
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
void Bot::handle(const string& msg){
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
        this-> send(str);
        }
    };
void Bot::send_msg(nlohmann::json& reqMsg){
    }
void Bot::load_plugin(const fs::path& path){
    auto plugin = boost::dll::import_symbol<BotPluginApi>(path,"plugin",dll::load_mode::append_decorations);
    plugin->init(this);
    string name = plugin -> name;
    cout << "加载插件：" << name <<std::endl;
    for(string command : plugin -> commands){
        cout << "plugin_command:" << command << std::endl;
        this->commands[command] = name;
    }
    plugins[name] = std::move(plugin);
    };


string Bot::command(const string& command,const string& arg){
   if(this->commands.contains(command)){
        return ((this->plugins)[(this->commands)[command]] -> execute(command));
    }
    return string("");
};
#define WS_CLIENT_CPP
#endif
