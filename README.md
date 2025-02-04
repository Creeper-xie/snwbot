# snwbot

使用WebSocket正向连接到OneBot协议的 QQ 协议端的 Bot 。

## 现状
初初初初级阶段，会经常有大的改动
（插件还不能用   
打算后续用异步，再重写一些地方。。。   
咱是C++新手，代码质量很低（）   

## 依赖
[libhv](https://github.com/ithewei/libhv) 网络库   
[json](https://github.com/nlohmann/json) 解析json   
[toml++](https://github.com/marzer/tomlplusplus) 解析Toml配置文件    
[Boost](https://github.com/boostorg/boost) 提供Boost.DLL加载动态链接库插件   
## 构建
``` shell
cd src
g++ *.cpp -std=c++20
g++ *.o -lhv -lboost_filesystem
```


