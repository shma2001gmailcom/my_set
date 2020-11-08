//
// Created by misha on 11/8/20.
//

#include <cstdio>
#include "Set.h"

Set::Set()
{
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
    size = 0;
}

Set::~Set()
{
    delete[] array;
}

bool Set::is_empty()
{
    return size == 0;
}

const bool Set::contains(const int &element) const
{
    return in(element, array, size);
}

bool Set::add(const int &element)
{
    if (contains(element))
    {
        return false;
    }
    if (size <= capacity)
    {
        array[size] = element;
        ++size;
        return true;
    }
    increase_capacity();
    add(element);
    return true;
}

void Set::increase_capacity()
{
    auto *new_array = new int[2 * capacity];
    for (int i = 0; i < size; new_array[i] = array[i++]);
    capacity *= 2;
    printf("new capacity: %d\n", capacity);
    delete[] array;
    array = new_array;
}

int Set::get(const int &element)
{
    if (in(element, array, size))
    {
        return element;
    }
}

int Set::get_size()
{
    return size;
}

void Set::print()
{
    printf("\n============\n{");
    for (int i = 0; i < size; i == size - 1 ? printf("%d", array[i]) : printf("%d, ", array[i]), ++i);
    printf("}\n");
    printf("\ncapacity: %d\n", capacity);
    printf("size: %d\n=========\n\n", size);
}

Set *Set::common_part(const Set *another_set)
{
    auto *result = new Set;
    for (int i = 0; i < size; ++i)
    {
        if (another_set->contains(array[i]))
        {
            result->add(array[i]);
        }
    }
    return result;
}

Set *Set::unite(const Set *set)
{
    auto *result = new Set;
    for (int i = 0; i < size; result->add(array[i++]));
    for (int i = 0; i < set->size; result->add(set->array[i++]));
    return result;
}







