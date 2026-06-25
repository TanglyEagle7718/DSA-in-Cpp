#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <cstdint>
#include <memory>
#include <utility>

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

    class Node {
        public:
            T value;
            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;
            explicit Node(const T& value) : value(value), left(nullptr), right(nullptr) {};

            Node(const Node& other) 
                : value(other.value), 
                left(other.left ? std::make_unique<Node>(other->left) : nullptr), right(other.right ? std::make_unique<Node>(other->right) : nullptr) {}
    };

    std::unique_ptr<Node> root;
    size_t length = 0;

private:
    void _inorderTraversalHelper(const Node* node, std::vector<T>& list) const {
        if (!node) return;
        
        _inorderTraversalHelper(node->left.get(), list);
        list.push_back(node->value);
        _inorderTraversalHelper(node->right.get(), list);
        return;
    }

    bool _removeHelper(std::unique_ptr<Node>& node, const T& value) {
        if (!node) return false;

        if (value < node->value) {
            return _removeHelper(node->left, value);
        }

        if (value > node->value) {
            return _removeHelper(node->right, value);
        }

        if (!node->left && !node->right) {
            node.reset();
            return true;
        }

        if (!node->left) {
            node = std::move(node->right);
            return true;
        }

        if (!node->right) {
            node = std::move(node->left);
            return true;
        }

        Node* successor = node->right.get();
        while (successor->left) {
            successor = successor->left.get();
        }

        node->value = successor->value;
        return _removeHelper(node->right, successor->value);
    }

};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr), length(0) {};

template <typename T>
std::size_t BinarySearchTree<T>::size() const {
    return length;
}

template <typename T>
bool BinarySearchTree<T>::is_empty() const {
    return !root;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
    if (!root) {
        root = std::make_unique<Node>(value);
        this->length++;
        return;
    }
    
    Node* curr = root.get();
    while (true) {
        if (value < curr->value) {
            if (!curr->left) {
                curr->left = std::make_unique<Node>(value);
                length++;
                return;
            }
            curr = curr->left.get();
        } else if (value > curr->value) {
            if (!curr->right) {
                curr->right = std::make_unique<Node>(value);
                length++;
                return;
            }
            curr = curr->right.get();
        } else {
            return;
        }
    }
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& value) const {
    if (!root) {
        return false;
    }

    Node* curr = root.get();

    while (true) {
        if (value < curr->value) {
            if (!curr->left) {
                return false;
            } else {
                curr = curr->left.get();
            }
        } else if (value > curr->value) {
            if (!curr->right) {
                return false;
            } else {
                curr = curr->right.get();
            }
        } else {
            return true;
        }
    }

}

template <typename T>
void BinarySearchTree<T>::remove(const T& value) {
    if (_removeHelper(root, value)) {
        length--;
    }
}

template <typename T>
std::vector<T> BinarySearchTree<T>::inorder_traversal() const {
    
    Node* curr = root.get();
    std::vector<T> list;

    _inorderTraversalHelper(curr, list);

    return list;
}

template <typename T>
void BinarySearchTree<T>::clear() {
    length = 0;
    root.reset();
}

} // namespace dsa
