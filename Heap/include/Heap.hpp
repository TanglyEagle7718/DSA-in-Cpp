#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

namespace dsa {

template <typename T>
class MinHeap {
public:
    MinHeap();

    std::size_t size() const;
    bool is_empty() const;

    void push(const T& value);
    void pop();
    const T& top() const;

    void heapify(const std::vector<T>& values);
    std::vector<T> to_vector() const;

    void clear();
};

template <typename T>
void heapify(std::vector<T>& values);

template <typename T>
MinHeap<T>::MinHeap() {
    throw std::logic_error("TODO: implement MinHeap::MinHeap");
}

template <typename T>
std::size_t MinHeap<T>::size() const {
    throw std::logic_error("TODO: implement MinHeap::size");
}

template <typename T>
bool MinHeap<T>::is_empty() const {
    throw std::logic_error("TODO: implement MinHeap::is_empty");
}

template <typename T>
void MinHeap<T>::push(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement MinHeap::push");
}

template <typename T>
void MinHeap<T>::pop() {
    throw std::logic_error("TODO: implement MinHeap::pop");
}

template <typename T>
const T& MinHeap<T>::top() const {
    throw std::logic_error("TODO: implement MinHeap::top");
}

template <typename T>
void MinHeap<T>::heapify(const std::vector<T>& values) {
    (void)values;
    throw std::logic_error("TODO: implement MinHeap::heapify");
}

template <typename T>
std::vector<T> MinHeap<T>::to_vector() const {
    throw std::logic_error("TODO: implement MinHeap::to_vector");
}

template <typename T>
void MinHeap<T>::clear() {
    throw std::logic_error("TODO: implement MinHeap::clear");
}

template <typename T>
void heapify(std::vector<T>& values) {
    (void)values;
    throw std::logic_error("TODO: implement free function heapify");
}

} // namespace dsa
