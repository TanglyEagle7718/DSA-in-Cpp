#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

namespace dsa {

template <typename T>
class BinarySearchTree {
public:
    BinarySearchTree();

    std::size_t size() const;
    bool is_empty() const;

    void insert(const T& value);
    bool contains(const T& value) const;
    void remove(const T& value);

    std::vector<T> inorder_traversal() const;

    void clear();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    throw std::logic_error("TODO: implement BinarySearchTree::BinarySearchTree");
}

template <typename T>
std::size_t BinarySearchTree<T>::size() const {
    throw std::logic_error("TODO: implement BinarySearchTree::size");
}

template <typename T>
bool BinarySearchTree<T>::is_empty() const {
    throw std::logic_error("TODO: implement BinarySearchTree::is_empty");
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement BinarySearchTree::insert");
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& value) const {
    (void)value;
    throw std::logic_error("TODO: implement BinarySearchTree::contains");
}

template <typename T>
void BinarySearchTree<T>::remove(const T& value) {
    (void)value;
    throw std::logic_error("TODO: implement BinarySearchTree::remove");
}

template <typename T>
std::vector<T> BinarySearchTree<T>::inorder_traversal() const {
    throw std::logic_error("TODO: implement BinarySearchTree::inorder_traversal");
}

template <typename T>
void BinarySearchTree<T>::clear() {
    throw std::logic_error("TODO: implement BinarySearchTree::clear");
}

} // namespace dsa
