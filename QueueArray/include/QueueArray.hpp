#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa {

template <typename T>
class QueueArray {
public:
    QueueArray();

    std::size_t size() const;
    bool is_empty() const;

    void enqueue(const T& value);
    void dequeue();
    T& front();
    const T& front() const;

    void clear();
};

template <typename T>
QueueArray<T>::QueueArray() {
    throw std::logic_error("TODO: implement QueueArray::QueueArray");
}

template <typename T>
std::size_t QueueArray<T>::size() const {
    throw std::logic_error("TODO: implement QueueArray::size");
}

template <typename T>
bool QueueArray<T>::is_empty() const {
    throw std::logic_error("TODO: implement QueueArray::is_empty");
}

template <typename T>
void QueueArray<T>::enqueue(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement QueueArray::enqueue");
}

template <typename T>
void QueueArray<T>::dequeue() {
    throw std::logic_error("TODO: implement QueueArray::dequeue");
}

template <typename T>
T& QueueArray<T>::front() {
    throw std::logic_error("TODO: implement QueueArray::front");
}

template <typename T>
const T& QueueArray<T>::front() const {
    throw std::logic_error("TODO: implement QueueArray::front const");
}

template <typename T>
void QueueArray<T>::clear() {
    throw std::logic_error("TODO: implement QueueArray::clear");
}

} // namespace dsa
