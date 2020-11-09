//
// Created by misha on 11/9/20.
//

#include <cstdio>
#include "SortedList.h"

void SortedList::add(const int &x)//O(n)
{
    int pos_to_insert = first_greater_index(x);
    if (pos_to_insert > -1)
    {
        if (1 + size > capacity)
        {
            increase_capacity();
        }
        for (int i = size; i >= pos_to_insert; --i)
        {
            array[i] = array[i - 1];
        }
        array[pos_to_insert] = x;
        ++size;
    }

}

int SortedList::first_greater_index(const int &x) const//O(n)
{
    for (int i = 0; i < size; ++i)
    {
        int value = array[i];
        if (x > value)
        {
            continue;
        }
        if (x == value)
        {
            return -1;
        }
        return i;
    }
}

//nullable
int *SortedList::search(const int &x)//O(log n)
{
    return find(array, size, x);
}

SortedList::~SortedList()
{
    delete[] array;
}

SortedList::SortedList()
{
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
    size = 0;

}

void SortedList::increase_capacity()
{
    auto *new_array = new int[2 * capacity];
    for (int i = 0; i < size; new_array[i] = array[i++]);
    capacity *= 2;
    delete[] array;
    array = new_array;
}

void SortedList::print()
{
    printf("\n============\n{");
    for (int i = 0; i < size; i == size - 1 ? printf("%d", array[i]) : printf("%d, ", array[i]), ++i);
    printf("}\n");
    printf("\ncapacity: %d\n", capacity);
    printf("size: %d\n=========\n", size);

}

bool SortedList::is_empty()
{
    return size == 0;
}


int SortedList::get_at(int i) const
{
    return array[i];
}

int SortedList::get_size() const
{
    return size;
}







