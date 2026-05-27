#include "SinglyLinkedList.hpp"

#include <cassert>

void run_basic_tests() {
    dsa::SinglyLinkedList<int> list;

    assert(list.is_empty());
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    assert(!list.is_empty());
    assert(list.size() == 3);
    assert(list.at(0) == 5);
    assert(list.at(1) == 10);
    assert(list.at(2) == 20);

    list.insert(1, 7);
    assert(list.at(1) == 7);
    assert(list.contains(7));

    list.remove_at(1);
    assert(list.size() == 3);
    assert(list.at(1) == 10);

    list.clear();
    assert(list.is_empty());
}
