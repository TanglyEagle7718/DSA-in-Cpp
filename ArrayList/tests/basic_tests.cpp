#include "ArrayList.hpp"

#include <cassert>
#include <iostream>

void run_basic_tests() {
    dsa::ArrayList<int> list;

    assert(list.is_empty());
    assert(list.size() == 0);

    list.add(10);
    list.add(20);
    list.add(30);

    assert(!list.is_empty());
    assert(list.size() == 3);
    assert(list.get(0) == 10);
    assert(list.get(1) == 20);
    assert(list.get(2) == 30);

    list.set(1, 25);
    assert(list.get(1) == 25);
    assert(list.contains(25));

    list.remove(0);
    assert(list.size() == 2);
    assert(list.get(0) == 25);

    list.clear();
    assert(list.is_empty());
}
