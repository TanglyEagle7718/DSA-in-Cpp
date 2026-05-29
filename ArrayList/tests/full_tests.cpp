#include "ArrayList.hpp"

#include <cassert>
#include <stdexcept>

void run_full_tests() {
    dsa::ArrayList<int> list;

    // Constructor and initial state
    assert(list.is_empty());
    assert(list.size() == 0);

    // Sequential insertions
    for (int i = 0; i < 50; ++i) {
        list.add(i);
    }
    assert(!list.is_empty());
    assert(list.size() == 50);

    // Indexed access and membership
    for (int i = 0; i < 50; ++i) {
        assert(list.get(static_cast<std::size_t>(i)) == i);
        assert(list.contains(i));
    }

    // Update values
    list.set(0, 1000);
    list.set(25, 2500);
    list.set(49, 4900);
    assert(list.get(0) == 1000);
    assert(list.get(25) == 2500);
    assert(list.get(49) == 4900);

    // Remove from front, middle, and back
    list.remove(0);
    assert(list.size() == 49);
    list.remove(24);
    assert(list.size() == 48);
    list.remove(47);
    assert(list.size() == 47);

    // Containment after removals
    assert(!list.contains(1000));

    // Clear and reuse
    list.clear();
    assert(list.is_empty());
    assert(list.size() == 0);

    list.add(7);
    list.add(8);
    assert(list.size() == 2);
    assert(list.get(0) == 7);

    // Expected failures on invalid operations
    bool threw = false;
    try {
        (void)list.get(999);
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        list.remove(999);
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);
}
