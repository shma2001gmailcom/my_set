//
// Created by misha on 06/11/2020.
//
#include <iostream>
#include <sstream>
#include "Set.h"
#include "Parser.h"

using namespace std;

Set *Parser::parse_set()
{
    cout << "\ntype some numbers separated by space\n\n" << endl;
    string temp;
    stringstream s(get_input());
    auto *result = new Set;
    while (s >> temp)
    {
        cout << temp << endl;
        if (is_number(temp))
        {
            result->add(std::stoi(temp));
        }
    }
    return result;

}

string Parser::get_input()
{
    string str;
    getline(cin, str);
    return str;
}