#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa {

template <typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList();

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
SinglyLinkedList<T>::SinglyLinkedList() {
    throw std::logic_error("TODO: implement SinglyLinkedList::SinglyLinkedList");
}

template <typename T>
std::size_t SinglyLinkedList<T>::size() const {
    throw std::logic_error("TODO: implement SinglyLinkedList::size");
}

template <typename T>
bool SinglyLinkedList<T>::is_empty() const {
    throw std::logic_error("TODO: implement SinglyLinkedList::is_empty");
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement SinglyLinkedList::push_front");
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement SinglyLinkedList::push_back");
}

template <typename T>
void SinglyLinkedList<T>::insert(std::size_t index, const T& value) {
    (void)index;
    (void)value;
    throw std::logic_error("TODO: implement SinglyLinkedList::insert");
}

template <typename T>
void SinglyLinkedList<T>::remove_at(std::size_t index) {
    (void)index;
    throw std::logic_error("TODO: implement SinglyLinkedList::remove_at");
}

template <typename T>
T& SinglyLinkedList<T>::at(std::size_t index) {
    (void)index;
    throw std::logic_error("TODO: implement SinglyLinkedList::at");
}

template <typename T>
const T& SinglyLinkedList<T>::at(std::size_t index) const {
    (void)index;
    throw std::logic_error("TODO: implement SinglyLinkedList::at const");
}

template <typename T>
bool SinglyLinkedList<T>::contains(const T& value) const {
    (void)value;
    throw std::logic_error("TODO: implement SinglyLinkedList::contains");
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    throw std::logic_error("TODO: implement SinglyLinkedList::clear");
}

} // namespace dsa
