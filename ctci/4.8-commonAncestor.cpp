// 4.8 First Common Ancestor: 
// Design an algorithm and write code to find the first common ancestor
// of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
// necessarily a binary search tree.

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <queue>
#include <limits>
#include <unordered_map>
#include <unordered_set>

struct Node {
    Node(int value) : value(value) {}
    int value{0};
    std::shared_ptr<Node> right{nullptr};
    std::shared_ptr<Node> left{nullptr};
};

bool findNode(std::shared_ptr<Node> root, std::shared_ptr<Node> node) {
    if(root == nullptr || node == nullptr) {
        return false;
    }
    if(root == node) {
        return true;
    }
    return findNode(root->left, node) || findNode(root->right, node);
}

std::shared_ptr<Node> commonAncestor(std::shared_ptr<Node> root, std::shared_ptr<Node> a, std::shared_ptr<Node> b) {
    if(root == nullptr || a == nullptr || b == nullptr) {
        return nullptr;
    }
    auto foundLeftA = findNode(root->left, a);    
    auto foundLeftB = findNode(root->left, b);

    auto foundRightA = findNode(root->right, a);
    auto foundRightB = findNode(root->right, b);

    if((foundLeftA || foundLeftB) && (foundRightA || foundRightB)) {
        return root;
    } else if(foundLeftA && foundLeftB) {
        auto result = commonAncestor(root->left, a, b);
        return (result == nullptr ? root : result);
    } else if(foundRightA && foundRightB) {
        auto result = commonAncestor(root->right, a, b);
        return (result == nullptr ? root : result);
    } else {
        return nullptr;
    }
}

int main() {
    auto root = std::make_shared<Node>(1);

    auto n11 = std::make_shared<Node>(2);
    auto n12 = std::make_shared<Node>(3);

    auto n21 = std::make_shared<Node>(4);
    auto n22 = std::make_shared<Node>(5);
    
    auto n23 = std::make_shared<Node>(6);
    auto n24 = std::make_shared<Node>(7);
    
    auto n31 = std::make_shared<Node>(8);

    root->left = n11;
    root->right = n12;

    n11->left = n21;
    n11->right = n22;nullptr

    n12->left = n23;
    n12->right = n24;

    n21->left = n31;

    // Test 1
    assert(commonAncestor(root, n11, n12) == root);

    // Test 2
    assert(commonAncestor(root, n31, n22) == n11);

    // Test 3
    assert(commonAncestor(root, n31, n22) == n11);

    // Test 4
    assert(commonAncestor(root, n31, n21) == n11);

    // Test 5
    assert(commonAncestor(root, n11, n21) == root);

    // Test 6
    assert(commonAncestor(root, root, n11) == nullptr);

    // Test 7
    assert(commonAncestor(root, n31, n11) == root);

    return 0;
}
