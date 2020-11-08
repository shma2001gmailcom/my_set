//
// Created by misha on 06/11/2020.
//

#ifndef CPP_HWS_PARSER_H
#define CPP_HWS_PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "Set.h"

using namespace std;

class Parser
{
private:
    string get_input();

public:
    Set *parse_set();
};

inline static bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    for (; it != s.end() && std::isdigit(*it); ++it);
    return !s.empty() && it == s.end();
}

inline bool is_int(const std::string &s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
    char *p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

inline static bool is_numeric(const string &s)
{
    if (s.empty())
    {
        return false;
    }
    for (char i : s)
    {
        if (!isdigit(i))
        {
            return false;
        }
    }
    return true;
}

#endif //CPP_HWS_PARSER_H
