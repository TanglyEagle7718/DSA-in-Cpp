#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa {

template <typename T>
class StackArray {
public:
    StackArray();

    std::size_t size() const;
    bool is_empty() const;

    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;

    void clear();
};

template <typename T>
StackArray<T>::StackArray() {
    throw std::logic_error("TODO: implement StackArray::StackArray");
}

template <typename T>
std::size_t StackArray<T>::size() const {
    throw std::logic_error("TODO: implement StackArray::size");
}

template <typename T>
bool StackArray<T>::is_empty() const {
    throw std::logic_error("TODO: implement StackArray::is_empty");
}

template <typename T>
void StackArray<T>::push(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement StackArray::push");
}

template <typename T>
void StackArray<T>::pop() {
    throw std::logic_error("TODO: implement StackArray::pop");
}

template <typename T>
T& StackArray<T>::top() {
    throw std::logic_error("TODO: implement StackArray::top");
}

template <typename T>
const T& StackArray<T>::top() const {
    throw std::logic_error("TODO: implement StackArray::top const");
}

template <typename T>
void StackArray<T>::clear() {
    throw std::logic_error("TODO: implement StackArray::clear");
}

} // namespace dsa
