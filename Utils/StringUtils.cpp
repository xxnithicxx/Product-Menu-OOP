#include "StringUtils.h"

vector<string> StringUtils::split(string str, string delimiter)
{
    vector<string> tokens;
    size_t pos = 0;
    string token;
    pos = str.find(delimiter);

    token = str.substr(0, pos);
    tokens.push_back(token);
    str.erase(0, pos + delimiter.length());

    tokens.push_back(str);
    return tokens;
}

vector<string> StringUtils::find(string str, regex match)
{
    vector<string> tokens;
    smatch sm;
    while (regex_search(str, sm, match))
    {
        tokens.push_back(sm.str());
        str = sm.suffix();
    }
    return tokens;
}