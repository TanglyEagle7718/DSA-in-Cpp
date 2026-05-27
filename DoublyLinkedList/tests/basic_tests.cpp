#include "DoublyLinkedList.hpp"

#include <cassert>

void run_basic_tests() {
    dsa::DoublyLinkedList<int> list;

    assert(list.is_empty());
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);

    assert(!list.is_empty());
    assert(list.size() == 3);
    assert(list.at(0) == 0);
    assert(list.at(2) == 2);

    list.insert(2, 7);
    assert(list.at(2) == 7);
    assert(list.contains(7));

    list.remove_at(2);
    assert(list.size() == 3);
    assert(list.at(2) == 2);

    list.clear();
    assert(list.is_empty());
}
