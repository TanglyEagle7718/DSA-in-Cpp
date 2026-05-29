#include "DoublyLinkedList.hpp"

#include <cassert>
#include <stdexcept>

void run_full_tests() {
    dsa::DoublyLinkedList<int> list;

    // Initial state
    assert(list.is_empty());
    assert(list.size() == 0);

    // Mixed insertions
    list.push_back(2);
    list.push_front(1);
    list.push_back(4);
    list.insert(2, 3);
    list.insert(4, 5);

    assert(list.size() == 5);
    for (int i = 0; i < 5; ++i) {
        assert(list.at(static_cast<std::size_t>(i)) == i + 1);
    }

    // Contains
    assert(list.contains(1));
    assert(list.contains(3));
    assert(list.contains(5));
    assert(!list.contains(999));

    // Remove head, middle, tail
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
    list.push_front(42);
    assert(list.at(0) == 42);

    // Invalid index operations
    bool threw = false;
    try {
        (void)list.at(100);
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        list.insert(100, 1);
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);
}
