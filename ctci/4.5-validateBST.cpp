// 4.5 Validate BST:
// Implement a function to check if a binary tree is a binary search tree.

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <queue>
#include <limits>

struct Node {
    Node(int value) : value(value) {} 

    int value{0};
    std::shared_ptr<Node> left{nullptr};
    std::shared_ptr<Node> right{nullptr};
};


void visit(std::shared_ptr<Node> root, std::vector<int>& stat) {
    if(root == nullptr) {
        return;
    } 
    visit(root->left, stat);
    if(!stat.empty()) {
        auto last = stat.back();
        if(last > root->value) {
            stat.clear();
            return;
        } else {
            stat.push_back(root->value);
        }
    } else {
        return;
    }
    visit(root->right, stat);
}

bool validateBST(std::shared_ptr<Node> root) {
    if(root == nullptr) {
        return false;
    }
    std::vector<int> stat = {std::numeric_limits<int>::min()};
    visit(root, stat);
    return !stat.empty();
}

int main() {
    // Test 1 - BST
    {
        auto root = std::make_shared<Node>(6);
        auto n11 = std::make_shared<Node>(4);
        auto n12 = std::make_shared<Node>(8);
        auto n21 = std::make_shared<Node>(2);
        auto n22 = std::make_shared<Node>(5);
        auto n23 = std::make_shared<Node>(7);
        auto n24 = std::make_shared<Node>(9);
        auto n31 = std::make_shared<Node>(1);
        auto n32 = std::make_shared<Node>(3);

        root->left = n11;
        root->right = n12;

        n11->left = n21;
        n11->right = n22;

        n12->left = n23;
        n12->right = n24;

        n21->left = n31;
        n21->right = n32;

        assert(validateBST(root) == true);
    }

    // Test 2 - not BST
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

        assert(validateBST(root) == false);
    }

    return 0;
}
