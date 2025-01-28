#include <array>
#include <regex>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::regex;
using std::regex_match;
using std::smatch;

// 把msg转化为command然后执行，返回string。
vector<string> msgToComand(string& msg);
string command(vector<string>& command);


