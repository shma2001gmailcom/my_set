//
// Created by misha on 11/8/20.
//

#ifndef MY_SET_SET_H
#define MY_SET_SET_H

#include "Set.h"
#include "SortedList.h"

class Set
{
public:
    Set();

    virtual ~Set();

    bool is_empty() const;

    const bool contains(const unsigned int &element) const;

    bool add(const unsigned int &element) const;

    unsigned int *get(const int &element) const;

    int get_size() const;

    Set *unite(const Set *set) const;

    Set *common_part(const Set *another_set) const;

    void print() const;

    int get_at(const int& i) const;

private:
    SortedList *array;
};

#endif //MY_SET_SET_H
