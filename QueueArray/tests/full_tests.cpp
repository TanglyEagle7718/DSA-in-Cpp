#include "QueueArray.hpp"

#include <cassert>
#include <stdexcept>

void run_full_tests() {
    dsa::QueueArray<int> queue;

    // Initial state
    assert(queue.is_empty());
    assert(queue.size() == 0);

    // Enqueue a sequence
    for (int i = 1; i <= 60; ++i) {
        queue.enqueue(i);
    }
    assert(queue.size() == 60);
    assert(queue.front() == 1);

    // Dequeue some and verify FIFO
    for (int i = 1; i <= 25; ++i) {
        assert(queue.front() == i);
        queue.dequeue();
    }
    assert(queue.size() == 35);
    assert(queue.front() == 26);

    // Additional enqueue to stress potential wrap-around logic
    for (int i = 61; i <= 90; ++i) {
        queue.enqueue(i);
    }
    assert(queue.size() == 65);
    assert(queue.front() == 26);

    // Drain queue
    for (int i = 26; i <= 90; ++i) {
        assert(queue.front() == i);
        queue.dequeue();
    }
    assert(queue.is_empty());

    // Invalid operations
    bool threw = false;
    try {
        (void)queue.front();
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        queue.dequeue();
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);
}
