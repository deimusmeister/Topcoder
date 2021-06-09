// 4.6 Successor: 
// Write an algorithm to find the "next" node (i .e., in-order successor) of a given node in a
// binary search tree. You may assume that each node has a link to its parent.

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <queue>
#include <limits>

struct Node {
    Node(int value) : value(value) {} 

    int value{0};
    std::shared_ptr<Node> parent{nullptr};
    std::shared_ptr<Node> left{nullptr};
    std::shared_ptr<Node> right{nullptr};
};

std::shared_ptr<Node> successor(std::shared_ptr<Node> node) {
    if(node == nullptr) {
        return nullptr;
    }
    if(node->left != nullptr) {
        return node->left;
    }
    if(node->parent == nullptr) {
        return nullptr;
    }

    if(node->parent->right == node) {
        return node->parent;
    }
    if(node->parent->left == node) {
        while(node->parent) {
            if(node->parent->right == node) {
                return node->parent; 
            }
            node = node->parent;
        }
    }
    return nullptr;
}

int main() {
    auto root = std::make_shared<Node>(6);
    auto n11 = std::make_shared<Node>(4);
    auto n12 = std::make_shared<Node>(8);
    auto n21 = std::make_shared<Node>(2);
    auto n22 = std::make_shared<Node>(5);
    auto n23 = std::make_shared<Node>(7);
    auto n24 = std::make_shared<Node>(9);
    auto n31 = std::make_shared<Node>(1);
    auto n32 = std::make_shared<Node>(3);
    auto n41 = std::make_shared<Node>(11);
    auto n51 = std::make_shared<Node>(15);

    root->left = n11;
    root->right = n12;
    n11->parent = root;
    n12->parent = root;

    n11->left = n21;
    n11->right = n22;
    n21->parent = n11;
    n22->parent = n11;

    n12->left = n23;
    n12->right = n24;
    n23->parent = n12;
    n24->parent = n12;

    n21->left = n31;
    n21->right = n32;
    n31->parent = n21;
    n32->parent = n21;

    n23->left = n41;
    n41->parent = n23;

    n41->left = n51;
    n51->parent = n41;

    assert(successor(root) == n11);
    assert(successor(n11) == n21);
    assert(successor(n12) == n23);
    
    assert(successor(n23) == n41);
    assert(successor(n41) == n51);
    assert(successor(n51) == root);

    return 0;
}
