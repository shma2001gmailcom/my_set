#include <cstdio>
#include "Set.h"
#include "Parser.h"

Set *make_set_internally();

Set *make_set_from_input();

int main()
{
    auto set = make_set_internally();
    auto anotherSet = make_set_from_input();
    auto intersection = set->common_part(anotherSet);
    cout << "intersection: " << endl;
    intersection->print();
    auto _union = set->unite(anotherSet);
    cout << "union: " << endl;
    _union->print();
    for (int i = 0; i < set->get_size(); ++i)
    {
        cout << set->get_at(i) << endl;
    }
    return 0;
}

Set *make_set_from_input()
{
    auto *parser = new Parser;
    auto anotherSet = parser->parse_set();
    anotherSet->print();
    return anotherSet;
}

Set *make_set_internally()
{
    auto *set = new Set();
    for (unsigned int i = 0; i < 11; ++i)
    {
        set->add(i % 2 == 0 ? i / 2 : i);
    }
    set->print();
    printf("is set empty? %s\n", set->is_empty() ? "true" : "false");
    unsigned int *pInt = set->get(11);
    if (set->contains(11))
    {
        cout << "get 11: %d\n" << *pInt << endl;
    } else
    {
        cout << "not contains 11" << endl;
    }
    printf("contains 23? %s\n", set->contains(23) ? "true" : "false");
    printf("contains 97? %s\n", set->contains(27) ? "true" : "false");
    printf("size: %d", set->get_size());
    return set;
}