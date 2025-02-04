// Copyright Antony Polukhin, 2016-2025.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef PLUGIN_API_HPP
#define PLUGIN_API_HPP

#include "hv/wsdef.h"
#include <boost/config.hpp>
#include <boost/dll/import.hpp>
#include <hv/WebSocketClient.h>
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
    virtual string execute() =0;
    string name;
    string author;
    toml::table config;
    std::vector<string> commands;
    std::function<void(string)>* send;
    map<string,boost::shared_ptr<BotPluginApi>>* plugins;
};
   
#endif

