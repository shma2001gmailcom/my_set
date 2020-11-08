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

static bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    for (; it != s.end() && std::isdigit(*it); ++it);
    return !s.empty() && it == s.end();
}

#endif //CPP_HWS_PARSER_H
