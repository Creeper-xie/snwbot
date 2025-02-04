#include <string>
#include "command.hpp"
using std::string;

string command(const string& command,const string& arg,map<string,apiPtr>& plugins,map<string,string>& commands){
   if(commands.contains(command)){
        return plugins[command] -> execute();
    }
    return string("");
};


