#include "CircularLinkedList.hpp"

#include <cassert>
#include <stdexcept>

void run_full_tests() {
    dsa::CircularLinkedList<int> list;

    // Initial state
    assert(list.is_empty());
    assert(list.size() == 0);

    // Insertions and positional checks
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.insert(2, 15);

    assert(list.size() == 4);
    assert(list.at(0) == 5);
    assert(list.at(1) == 10);
    assert(list.at(2) == 15);
    assert(list.at(3) == 20);

    // Contains behavior
    assert(list.contains(5));
    assert(list.contains(15));
    assert(!list.contains(99));

    // Remove head, middle, tail
    list.remove_at(0);
    assert(list.size() == 3);
    assert(list.at(0) == 10);

    list.remove_at(1);
    assert(list.size() == 2);
    assert(list.at(1) == 20);

    list.remove_at(1);
    assert(list.size() == 1);
    assert(list.at(0) == 10);

    // Clear and repopulate
    list.clear();
    assert(list.is_empty());
    for (int i = 0; i < 8; ++i) {
        list.push_back(i);
    }
    assert(list.size() == 8);
    for (int i = 0; i < 8; ++i) {
        assert(list.at(static_cast<std::size_t>(i)) == i);
    }

    // Invalid operations should fail
    bool threw = false;
    try {
        (void)list.at(100);
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        list.remove_at(100);
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);
}
