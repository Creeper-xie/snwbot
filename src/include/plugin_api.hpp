#pragma once

#include <boost/config.hpp>
#include <boost/dll/import.hpp>
#include <functional>
#include <toml++/toml.hpp>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Bot;

class BOOST_SYMBOL_VISIBLE BotPluginApi {
public:
    virtual ~BotPluginApi() = default;
    virtual void init(std::map<std::string,boost::shared_ptr<BotPluginApi>>* plugins){
        this->plugins = plugins;
    };
    virtual std::string execute(std::string) =0;
    virtual void import(std::string plugin){
        
    }
    Bot* bot;
    std::string name;
    std::string author;
    int version[2];
    toml::table config;
    std::vector<std::string> importedPlugin;
    std::vector<std::string> dep;
    std::map<std::string,std::string> commandToDescr;
    std::map<std::string,std::string> commandToPlugin;
    std::map<std::string,boost::shared_ptr<BotPluginApi>>* plugins;
};
   
