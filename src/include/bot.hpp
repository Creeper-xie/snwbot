#pragma once

#include <nlohmann/json.hpp>
#include <map>
#include <string>

class Bot;

#include "plugin_api.hpp"

using apiPtr = boost::shared_ptr<BotPluginApi>;

class Bot{
public:
    
    void load_plugin(const boost::filesystem::path& path);
    std::map<std::string,apiPtr> plugins;
};

