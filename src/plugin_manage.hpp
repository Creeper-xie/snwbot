#include <boost/dll/import.hpp>
#include <boost/filesystem.hpp>
#include <string>
#include <map>
#include <vector>

#include "ws_client.hpp"
#include "plugin_api.hpp"

namespace dll = boost::dll;
namespace fs = boost::filesystem;

using apiPtr = boost::shared_ptr<BotPluginApi>;
void loadPlugin(std::map<std::string,apiPtr>& plugins,std::map<string,string>& commands,const fs::path& path,BotWebSocketClient& ws);
