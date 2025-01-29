# snwbot

试图写一个qqbot，主要是给自己用的（？）

## 现状

机器人现在只能勉强发消息，发一次消息后会error
> terminate called after throwing an instance of 'nlohmann::json_abi_v3_11_3::detail::type_error'
>  what():  [json.exception.type_error.302] type must be string, but is null
>zsh: IOT instruction  ./a.out

## 依赖
网络库：[libhv](https://github.com/ithewei/libhv)   
json库：[json](https://github.com/nlohmann/json)   

## 构建
``` shelli
cd src
g++ *.cpp
g++ *.o -lhv
```


