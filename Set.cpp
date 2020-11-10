//
// Created by misha on 11/8/20.
//

#include "Set.h"

using namespace std;

Set::Set()
{
    array = new SortedList;
}

Set::~Set()
{
    delete[] array;
}

bool Set::is_empty() const//O(1)
{
    return array->is_empty();
}

const bool Set::contains(const unsigned int &element) const//O(log n)
{
    return array->search(element) != nullptr;
}

bool Set::add(const unsigned int &element) const
{
    array->add(element);
}

//nullable
unsigned int *Set::get(const int &element) const
{
    unsigned int *index = array->search(element);
    if (index == nullptr)
    {
        return index;
    }
    int i = array->get_at(*index);
    return new unsigned int(i);
}

int Set::get_size() const
{
    return array->get_size();
}

Set *Set::common_part(const Set *another_set) const
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

Set *Set::unite(const Set *set) const
{
    auto *result = new Set;
    for (int i = 0; i < get_size(); result->add(array->get_at(i++)));
    for (int i = 0; i < set->get_size(); result->add(set->array->get_at(i++)));
    return result;
}

void Set::print() const
{
    array->print();
}

//iterate through set
int Set::get_at(const int &i) const
{
    return array->get_at(i);
}









