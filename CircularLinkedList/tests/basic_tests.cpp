#include "CircularLinkedList.hpp"

#include <cassert>

void run_basic_tests() {
    dsa::CircularLinkedList<int> list;

    assert(list.is_empty());
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    assert(!list.is_empty());
    assert(list.size() == 3);
    assert(list.at(0) == 5);
    assert(list.at(1) == 10);
    assert(list.at(2) == 20);

    list.insert(2, 15);
    assert(list.at(2) == 15);
    assert(list.contains(15));

    list.remove_at(2);
    assert(list.size() == 3);
    assert(list.at(2) == 20);

    list.clear();
    assert(list.is_empty());
}
