#include "SinglyLinkedList.hpp"

#include <cassert>
#include <stdexcept>

void run_full_tests() {
    dsa::SinglyLinkedList<int> list;

    // Initial state
    assert(list.is_empty());
    assert(list.size() == 0);

    // Push front/back and position checks
    list.push_front(2);
    list.push_front(1);
    list.push_back(3);
    list.push_back(5);
    list.insert(3, 4);

    assert(list.size() == 5);
    assert(list.at(0) == 1);
    assert(list.at(1) == 2);
    assert(list.at(2) == 3);
    assert(list.at(3) == 4);
    assert(list.at(4) == 5);

    // Contains checks
    for (int value = 1; value <= 5; ++value) {
        assert(list.contains(value));
    }

    // Removals at boundaries and middle
    list.remove_at(0);
    assert(list.size() == 4);
    assert(list.at(0) == 2);

    list.remove_at(1);
    assert(list.size() == 3);
    assert(list.at(1) == 4);

    list.remove_at(2);
    assert(list.size() == 2);
    assert(list.at(1) == 4);

    // Clear and reuse
    list.clear();
    assert(list.is_empty());
    list.push_back(10);
    assert(list.at(0) == 10);

    // Invalid index checks
    bool threw = false;
    try {
        (void)list.at(10);
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        list.remove_at(10);
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);
}
