#include "StackArray.hpp"

#include <cassert>

void run_basic_tests() {
    dsa::StackArray<int> stack;

    assert(stack.is_empty());
    stack.push(1);
    stack.push(2);
    stack.push(3);

    assert(!stack.is_empty());
    assert(stack.size() == 3);
    assert(stack.top() == 3);

    stack.pop();
    assert(stack.size() == 2);
    assert(stack.top() == 2);

    stack.clear();
    assert(stack.is_empty());
}
