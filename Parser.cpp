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
            result->add(static_cast<const unsigned int &>(std::stoi(temp)));
        }
        else __throw_invalid_argument("input should consist of unsigned ints");
    }
    return result;
}

string Parser::get_input() const
{
    string str;
    getline(cin, str);
    return str;
}