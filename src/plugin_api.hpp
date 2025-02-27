#ifndef PLUGIN_API_HPP
#define PLUGIN_API_HPP

#include <boost/config.hpp>
#include <boost/dll/import.hpp>
#include <functional>
#include <toml++/toml.hpp>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "bot.hpp"


class BOOST_SYMBOL_VISIBLE BotPluginApi {
public:
    virtual ~BotPluginApi() = default;
    virtual void init(Bot& bot) =0;
    virtual std::string execute(std::string) =0;
    Bot bot;
    std::string name;
    std::string author;
    int version[2];
    toml::table config;
    std::vector<std::string> commands;
    std::function<void(std::string)>* send;
    std::map<std::string,boost::shared_ptr<BotPluginApi>>* plugins;
};
   
#endif

