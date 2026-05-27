#include "Heap.hpp"

#include <cassert>
#include <vector>

void run_basic_tests() {
    dsa::MinHeap<int> heap;

    assert(heap.is_empty());

    heap.push(30);
    heap.push(10);
    heap.push(20);

    assert(!heap.is_empty());
    assert(heap.size() == 3);
    assert(heap.top() == 10);

    heap.pop();
    assert(heap.size() == 2);

    heap.heapify(std::vector<int>{9, 4, 7, 1});
    assert(heap.top() == 1);

    std::vector<int> data{5, 2, 8, 3};
    dsa::heapify(data);

    heap.clear();
    assert(heap.is_empty());
}
