#include <string>

#include "plugin_api.hpp"

using std::string;
using apiPtr = boost::shared_ptr<BotPluginApi>;

string command(const string& command,const string& arg,map<string,apiPtr>* plugins,map<string,string>* commands);


