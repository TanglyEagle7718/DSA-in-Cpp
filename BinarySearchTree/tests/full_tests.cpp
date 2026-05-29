#include "BinarySearchTree.hpp"

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <vector>

void run_full_tests() {
    dsa::BinarySearchTree<int> tree;

    // Initial state
    assert(tree.is_empty());
    assert(tree.size() == 0);

    // Insert values
    const std::vector<int> values{50, 30, 70, 20, 40, 60, 80};
    for (int value : values) {
        tree.insert(value);
    }
    assert(tree.size() == values.size());
    assert(!tree.is_empty());

    // Contains checks
    for (int value : values) {
        assert(tree.contains(value));
    }
    assert(!tree.contains(999));

    // Inorder traversal should be sorted
    const auto inorder = tree.inorder_traversal();
    assert(inorder.size() == values.size());
    assert(std::is_sorted(inorder.begin(), inorder.end()));

    // Remove leaf, single-child, and two-child style targets
    tree.remove(20);
    assert(!tree.contains(20));

    tree.remove(30);
    assert(!tree.contains(30));

    tree.remove(50);
    assert(!tree.contains(50));

    // Size tracks removals
    assert(tree.size() == 4);

    // Remove missing value should fail or no-op by implementation choice.
    // Here we assert that it does not create corruption by checking sorted traversal.
    bool threw = false;
    try {
        tree.remove(12345);
    } catch (const std::exception&) {
        threw = true;
    }
    (void)threw;

    const auto inorder_after = tree.inorder_traversal();
    assert(std::is_sorted(inorder_after.begin(), inorder_after.end()));

    // Clear and reuse
    tree.clear();
    assert(tree.is_empty());
    tree.insert(1);
    assert(tree.contains(1));
}
