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
    string get_input() const;

public:
    Set *parse_set() const;
};

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
