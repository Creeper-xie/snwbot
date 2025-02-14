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


using std::string;
using std::map;
using std::cout;

class BOOST_SYMBOL_VISIBLE BotPluginApi {
public:
    virtual ~BotPluginApi() = default;
    virtual void init(std::function<void(string)>* send,map<string,boost::shared_ptr<BotPluginApi>>* plugins) =0;
    virtual string execute(string) =0;
    string name;
    string author;
    int version[2];
    toml::table config;
    std::vector<string> commands;
    std::function<void(string)>* send;
    map<string,boost::shared_ptr<BotPluginApi>>* plugins;
};
   
#endif

