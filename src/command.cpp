#include <string>

using std::string;

string command(const string& command,const string& arg){
   if(command == "自我介绍"){
        return string("咱是帕酱喵，是来自萌国的猫娘！\n 项目地址： https://codeberg.org/Sniventals/snwbot");
    }
    return string("");
};


