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

    bool is_empty();

    const bool contains(const int& element)const;

    bool add(const int& element);

    int* get(const int& element);

    int get_size()const;

    Set *unite(const Set *set);

    Set *common_part(const Set *another_set);

    void print();

private:
    SortedList *array;
};

static inline const bool in(const int& element, const int *elements, const int& size)
{
    for (int i = 0; i < size; ++i)
    {
        if (*(elements++) == element)
        {
            return true;
        }
    }
    return false;
}

#endif //MY_SET_SET_H
