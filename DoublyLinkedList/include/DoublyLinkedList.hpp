#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa {

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();

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
DoublyLinkedList<T>::DoublyLinkedList() {
    throw std::logic_error("TODO: implement DoublyLinkedList::DoublyLinkedList");
}

template <typename T>
std::size_t DoublyLinkedList<T>::size() const {
    throw std::logic_error("TODO: implement DoublyLinkedList::size");
}

template <typename T>
bool DoublyLinkedList<T>::is_empty() const {
    throw std::logic_error("TODO: implement DoublyLinkedList::is_empty");
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement DoublyLinkedList::push_front");
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement DoublyLinkedList::push_back");
}

template <typename T>
void DoublyLinkedList<T>::insert(std::size_t index, const T& value) {
    (void)index;
    (void)value;
    throw std::logic_error("TODO: implement DoublyLinkedList::insert");
}

template <typename T>
void DoublyLinkedList<T>::remove_at(std::size_t index) {
    (void)index;
    throw std::logic_error("TODO: implement DoublyLinkedList::remove_at");
}

template <typename T>
T& DoublyLinkedList<T>::at(std::size_t index) {
    (void)index;
    throw std::logic_error("TODO: implement DoublyLinkedList::at");
}

template <typename T>
const T& DoublyLinkedList<T>::at(std::size_t index) const {
    (void)index;
    throw std::logic_error("TODO: implement DoublyLinkedList::at const");
}

template <typename T>
bool DoublyLinkedList<T>::contains(const T& value) const {
    (void)value;
    throw std::logic_error("TODO: implement DoublyLinkedList::contains");
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    throw std::logic_error("TODO: implement DoublyLinkedList::clear");
}

} // namespace dsa
