//
// Created by misha on 11/8/20.
//

#include "Set.h"
#include <cstdio>

using namespace std;

Set::Set()
{
    array = new SortedList;
}

Set::~Set()
{
    delete[] array;
}

bool Set::is_empty()
{
    return array->is_empty();
}

const bool Set::contains(const int &element) const
{
    return array->search(element) != nullptr;
}

bool Set::add(const int &element)
{
    array->add(element);
}

//nullable
int *Set::get(const int &element)
{
    int *index = array->search(element);
    if (index == nullptr)
    { return index; }
    int i = array->get_at(*index);
    return new int(i);
}

int Set::get_size() const
{
    return array->get_size();
}

Set *Set::common_part(const Set *another_set)
{
    auto *result = new Set;
    for (int i = 0; i < get_size(); ++i)
    {
        int element = array->get_at(i);
        if (another_set->contains(element))
        {
            result->add(element);
        }
    }
    return result;
}

Set *Set::unite(const Set *set)
{
    auto *result = new Set;
    for (int i = 0; i < get_size(); result->add(array->get_at(i++)));
    for (int i = 0; i < set->get_size(); result->add(set->array->get_at(i++)));
    return result;
}

void Set::print()
{
    array->print();
}







