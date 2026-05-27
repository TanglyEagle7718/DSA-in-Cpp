#include "QueueArray.hpp"

#include <cassert>

void run_basic_tests() {
    dsa::QueueArray<int> queue;

    assert(queue.is_empty());
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    assert(!queue.is_empty());
    assert(queue.size() == 3);
    assert(queue.front() == 10);

    queue.dequeue();
    assert(queue.size() == 2);
    assert(queue.front() == 20);

    queue.clear();
    assert(queue.is_empty());
}
