// 4.4 Check Balanced: 
// Implement a function to check if a binary tree is balanced. For the purposes of
// this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
// node never differ by more than one.

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <queue>

struct Node {
    Node(int value) : value(value) {} 

    int value{0};
    std::shared_ptr<Node> left{nullptr};
    std::shared_ptr<Node> right{nullptr};
};

int get_height(std::shared_ptr<Node> root) {
    if(root == nullptr) {
        return 0;
    }
    int left = get_height(root->left);
    int right = get_height(root->right);
    return 1 + std::max(left, right);
}


bool checkBalanced(std::shared_ptr<Node> root) {
    if(root == nullptr) {
        return true;
    }
    auto left = get_height(root->left);
    auto right = get_height(root->right);
    if(std::abs(left - right) > 1) {
        return false;
    } else {
        return checkBalanced(root->left) && checkBalanced(root->right);
    }
}

int main() {
    // Test 1 - balanced
    {
        auto root = std::make_shared<Node>(1);
        auto n11 = std::make_shared<Node>(2);
        auto n12 = std::make_shared<Node>(3);
        auto n21 = std::make_shared<Node>(5);
        auto n22 = std::make_shared<Node>(6);
        auto n23 = std::make_shared<Node>(7);
        auto n24 = std::make_shared<Node>(8);
        auto n31 = std::make_shared<Node>(9);
        auto n32 = std::make_shared<Node>(10);

        root->left = n11;
        root->right = n12;

        n11->left = n21;
        n11->right = n22;

        n12->left = n23;
        n12->right = n24;

        n21->left = n31;
        n21->right = n32;

        assert(checkBalanced(root) == true);
    }

    // Test 2 - unbalanced
    {
        auto root = std::make_shared<Node>(1);
        auto n11 = std::make_shared<Node>(2);
        auto n12 = std::make_shared<Node>(3);
        auto n21 = std::make_shared<Node>(5);
        auto n22 = std::make_shared<Node>(6);
        auto n23 = std::make_shared<Node>(7);
        auto n24 = std::make_shared<Node>(8);
        auto n31 = std::make_shared<Node>(9);
        auto n32 = std::make_shared<Node>(10);
        auto n41 = std::make_shared<Node>(11);

        root->left = n11;
        root->right = n12;

        n11->left = n21;
        n11->right = n22;

        n12->left = n23;
        n12->right = n24;

        n21->left = n31;
        n21->right = n32;

        n31->left = n41;

        assert(checkBalanced(root) == false);
    }

    return 0;
}
