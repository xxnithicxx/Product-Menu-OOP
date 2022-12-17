#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

namespace StringUtils
{
    vector<string> split(string str, string delimiter);
    vector<string> find(string str, regex match);
}
