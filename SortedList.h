//
// Created by misha on 11/9/20.
//

#ifndef MY_SET_SORTEDARRAY_H
#define MY_SET_SORTEDARRAY_H

#include <iostream>

using namespace std;

class SortedList
{
public:
    virtual ~SortedList();

    SortedList();

    bool is_empty() const;

    void add(const unsigned int &x);

    unsigned int *search(const unsigned int &x) const;

    void print() const;

    int get_size() const;

    int get_at(const unsigned int &i) const;

private:
    static const unsigned int INITIAL_CAPACITY = 67;
    unsigned int *array;
private:
    int capacity;
    unsigned int size;

    void increase_capacity();

    int first_greater_index(const unsigned int &element) const;


};

static int bin_search(const unsigned int *array, int left, int right, const int &element)//O(log n)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == element)
        {
            return mid;
        }
        if (array[mid] > element)
        {
            return bin_search(array, left, mid - 1, element);
        }
        return bin_search(array, mid + 1, right, element);
    }
    return -1;
}

static int least_greater_index(const unsigned int *array, unsigned int left, unsigned int right, const unsigned int &element)//O(log n)
{
    if (right - left == 0)
    {
        return 0;
    }
    unsigned int mid = left + (right - left) / 2;
    if (element == array[mid])
    {
        return -1;
    }
    if (right - left > 1)
    {
        mid = left + (right - left) / 2;
        if (element < array[mid])
        {
            right = mid;
            return least_greater_index(array, left, right, element);
        }
        left = mid;
        return least_greater_index(array, left, right, element);
    }
    return right;

}

//nullable
static unsigned int *find(const unsigned int *array, int array_length, int element)//O(log n)
{
    int i = bin_search(array, 0, array_length - 1, element);
    return i == -1 ? nullptr : new unsigned int(array[i]);
}

#endif //MY_SET_SORTEDARRAY_H


