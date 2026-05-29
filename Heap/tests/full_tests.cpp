#include "Heap.hpp"

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <vector>

void run_full_tests() {
    dsa::MinHeap<int> heap;

    // Initial state
    assert(heap.is_empty());
    assert(heap.size() == 0);

    // Push values and validate top
    heap.push(40);
    heap.push(10);
    heap.push(30);
    heap.push(20);
    assert(heap.size() == 4);
    assert(heap.top() == 10);

    // Pop and validate new top
    heap.pop();
    assert(heap.size() == 3);
    assert(heap.top() == 20);

    // Heapify from arbitrary sequence
    const std::vector<int> values{9, 4, 7, 1, 3, 6, 2};
    heap.heapify(values);
    assert(heap.size() == values.size());
    assert(heap.top() == 1);

    // Validate exported vector contains all values
    std::vector<int> exported = heap.to_vector();
    std::sort(exported.begin(), exported.end());
    std::vector<int> expected = values;
    std::sort(expected.begin(), expected.end());
    assert(exported == expected);

    // Standalone heapify function
    std::vector<int> data{11, 5, 8, 2, 14, 1};
    dsa::heapify(data);
    assert(!data.empty());
    assert(data.front() == 1);

    // Clear and invalid operations
    heap.clear();
    assert(heap.is_empty());

    bool threw = false;
    try {
        (void)heap.top();
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        heap.pop();
    } catch (const std::exception&) {
        threw = true;
    }
    assert(threw);
}
