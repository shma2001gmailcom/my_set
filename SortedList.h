//
// Created by misha on 11/9/20.
//

#ifndef MY_SET_SORTEDARRAY_H
#define MY_SET_SORTEDARRAY_H

class SortedList
{
public:
    static const int INITIAL_CAPACITY = 17;

    virtual ~SortedList();

    SortedList();

    bool is_empty();

    void add(const int &x);

    int *search(const int &x);

    void print();

    int get_size() const;

    int get_at(int i) const;

private:
    int *array;
private:
    int capacity;
    int size;

    void increase_capacity();

    int first_greater_index(const int &x) const;


};

//nullable
static int bin_search(const int *array, int left, int right, const int &element)
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

//nullable
static int *find(int *array, int array_length, int element)
{
    int i = bin_search(array, 0, array_length - 1, element);
    return i == -1 ? nullptr : new int(array[i]);
}

#endif //MY_SET_SORTEDARRAY_H


