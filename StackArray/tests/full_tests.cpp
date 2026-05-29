#include "StackArray.hpp"

#include <cassert>
#include <stdexcept>

void run_full_tests() {
    dsa::StackArray<int> stack;

    // Initial state
    assert(stack.is_empty());
    assert(stack.size() == 0);

    // Push many elements
    for (int i = 1; i <= 100; ++i) {
        stack.push(i);
        assert(stack.top() == i);
    }
    assert(stack.size() == 100);
    assert(!stack.is_empty());

    // Pop half and verify LIFO
    for (int i = 100; i >= 51; --i) {
        assert(stack.top() == i);
        stack.pop();
    }
    assert(stack.size() == 50);
    assert(stack.top() == 50);

    // Clear and reuse
    stack.clear();
    assert(stack.is_empty());
    stack.push(7);
    assert(stack.top() == 7);

    // Invalid operations
    stack.pop();
    bool threw = false;
    try {
        (void)stack.top();
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        stack.pop();
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);
}
