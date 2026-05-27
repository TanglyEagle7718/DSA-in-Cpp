#include "BinarySearchTree.hpp"

#include <cassert>

void run_basic_tests() {
    dsa::BinarySearchTree<int> tree;

    assert(tree.is_empty());

    tree.insert(20);
    tree.insert(10);
    tree.insert(30);

    assert(!tree.is_empty());
    assert(tree.size() == 3);
    assert(tree.contains(10));
    assert(tree.contains(20));
    assert(tree.contains(30));

    const auto traversal = tree.inorder_traversal();
    assert(traversal.size() == 3);
    assert(traversal[0] == 10);
    assert(traversal[1] == 20);
    assert(traversal[2] == 30);

    tree.remove(20);
    assert(tree.size() == 2);

    tree.clear();
    assert(tree.is_empty());
}
