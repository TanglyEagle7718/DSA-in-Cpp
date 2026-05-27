#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa {

template <typename T>
class CircularLinkedList {
public:
    CircularLinkedList();

    std::size_t size() const;
    bool is_empty() const;

    void push_front(const T& value);
    void push_back(const T& value);
    void insert(std::size_t index, const T& value);
    void remove_at(std::size_t index);

    T& at(std::size_t index);
    const T& at(std::size_t index) const;

    bool contains(const T& value) const;
    void clear();
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList() {
    throw std::logic_error("TODO: implement CircularLinkedList::CircularLinkedList");
}

template <typename T>
std::size_t CircularLinkedList<T>::size() const {
    throw std::logic_error("TODO: implement CircularLinkedList::size");
}

template <typename T>
bool CircularLinkedList<T>::is_empty() const {
    throw std::logic_error("TODO: implement CircularLinkedList::is_empty");
}

template <typename T>
void CircularLinkedList<T>::push_front(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement CircularLinkedList::push_front");
}

template <typename T>
void CircularLinkedList<T>::push_back(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement CircularLinkedList::push_back");
}

template <typename T>
void CircularLinkedList<T>::insert(std::size_t index, const T& value) {
    (void)index;
    (void)value;
    throw std::logic_error("TODO: implement CircularLinkedList::insert");
}

template <typename T>
void CircularLinkedList<T>::remove_at(std::size_t index) {
    (void)index;
    throw std::logic_error("TODO: implement CircularLinkedList::remove_at");
}

template <typename T>
T& CircularLinkedList<T>::at(std::size_t index) {
    (void)index;
    throw std::logic_error("TODO: implement CircularLinkedList::at");
}

template <typename T>
const T& CircularLinkedList<T>::at(std::size_t index) const {
    (void)index;
    throw std::logic_error("TODO: implement CircularLinkedList::at const");
}

template <typename T>
bool CircularLinkedList<T>::contains(const T& value) const {
    (void)value;
    throw std::logic_error("TODO: implement CircularLinkedList::contains");
}

template <typename T>
void CircularLinkedList<T>::clear() {
    throw std::logic_error("TODO: implement CircularLinkedList::clear");
}

} // namespace dsa
