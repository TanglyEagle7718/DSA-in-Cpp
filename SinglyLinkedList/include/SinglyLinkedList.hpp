#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <cstdint>
#include <memory>
#include <utility>

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


private:
    std::size_t length;

    class Node {
    public:
        T value;
        std::unique_ptr<Node> next;

        explicit Node(T value) : value(value), next(nullptr) {}
        explicit Node(T value, Node* next) : value(value), next(next ? std::make_unique<Node>(next) : nullptr) {}
    };
    std::unique_ptr<Node> head;
    Node* tail;

};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : length(0), head(nullptr), tail(nullptr) {}

template <typename T>
std::size_t SinglyLinkedList<T>::size() const {
    if (!head) return 0;
    return length;
}

template <typename T>
bool SinglyLinkedList<T>::is_empty() const {
    return !head;
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T& value) {
    if (!head) {
        head = std::make_unique<Node>(value);
        tail = head.get();

        length++;
        return;
    }

    auto newNode = std::make_unique<Node>(value);
    newNode->next = std::move(head);
    head = std::move(newNode);
    length++;

    return;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
    if (!head) {
        head = std::make_unique<Node>(value);
        tail = head.get();

        length++;
        return;
    }

    auto newNode = std::make_unique<Node>(value);
    
    Node* newTail = newNode.get();
    tail->next = std::move(newNode);
    tail = newTail;

    length++;
    return;
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
    if (!head) return;

    head.reset();
    tail = nullptr;
    length = 0;
}

} // namespace dsa
