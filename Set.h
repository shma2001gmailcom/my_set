//
// Created by misha on 11/8/20.
//

#ifndef MY_SET_SET_H
#define MY_SET_SET_H

class Set
{
public:
    virtual Set();

    virtual ~Set();

    bool is_empty();

    bool contains(int element);

    bool add(int element);

    int get(int element);

    int get_size();

    void print();

private:
    static const int INITIAL_CAPACITY = 17;
    int *array;
    int capacity;
    int size;

    void increase_capacity();

};

static bool in(int element, int *elements, int size)
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
