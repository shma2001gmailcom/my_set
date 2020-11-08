
#include <cstdio>
#include "Set.h"

int main()
{
    auto * set = new Set();
    for (int i = 0; i < 25; ++i) {
        set->add(i % 2 == 0 ? i/2: i);
    }
    set->print();
    printf("is set empty? %s\n", set->is_empty() ? "true" : "false");
    printf("get 11: %d\n", set->get(11));
    printf("contains 23? %s\n", set->contains(23) ? "true" : "false");
    printf("contains 97? %s\n", set->contains(27) ? "true" : "false");
    printf("size: %d", set->get_size());
    return 0;
}