//
// Created by misha on 06/11/2020.
//
#include <iostream>
#include <sstream>
#include "Set.h"
#include "Parser.h"

using namespace std;

Set *Parser::parse_set() const
{
    cout << "\ntype some non-negative integers separated by space\n\n" << endl;
    string temp;
    stringstream s(get_input());
    auto *result = new Set;
    while (s >> temp)
    {
        if (is_numeric(temp))
        {
            result->add(std::stoi(temp));
        }
    }
    return result;
}

string Parser::get_input() const
{
    string str;
    getline(cin, str);
    return str;
}