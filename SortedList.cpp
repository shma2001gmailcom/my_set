//
// Created by misha on 11/9/20.
//

#include <cstdio>
#include "SortedList.h"

SortedList::SortedList()
{
    capacity = INITIAL_CAPACITY;
    array = new unsigned int[capacity];
    size = 0;

}

SortedList::~SortedList()
{
    delete[] array;
}

void SortedList::add(const unsigned int &x)//O(n)
{
    int pos_to_insert = first_greater_index(x);//O(log n)
    if (pos_to_insert > -1)
    {
        if (1 + size > capacity)
        {
            increase_capacity();//O(n)
        }
        for (int i = size; i >= pos_to_insert; --i)//O(n)
        {
            array[i] = array[i - 1];//shift greater elements right
        }
        array[pos_to_insert] = x;
        ++size;
    }
}

//nullable
unsigned int *SortedList::search(const unsigned int &x) const//O(log n)
{
    return find(array, size, x);
}

bool SortedList::is_empty() const//O(1)
{
    return size == 0;
}

int SortedList::get_at(const unsigned int &i) const//O(1)
{
    if (i > size - 1) __throw_length_error("index out of array bound");
    return array[i];
}

int SortedList::get_size() const//O(1)
{
    return size;
}


int SortedList::first_greater_index(const unsigned int &element) const//O(log n)
{
    return least_greater_index(array, 0, size, element);//O(log n)
}



void SortedList::increase_capacity()//O(n); should be seldom-used
{
    auto *new_array = new unsigned int[2 * capacity];
    for (int i = 0; i < size; new_array[i] = array[i++]);
    capacity *= 2;
    delete[] array;
    array = new_array;
}

void SortedList::print() const
{
    printf("Set{");
    for (int i = 0; i < size; i == size - 1 ? printf("%d", array[i]) : printf("%d, ", array[i]), ++i);
    printf("}\n");
    printf("capacity: %d\n", capacity);
    printf("size: %d\n=========\n", size);

}








