// 4.10 Check Subtree: 
// T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an
// algorithm to determine if T2 is a subtree of T1.
// A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2.
// That is, if you cut off the tree at node n, the two trees would be identical.

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <queue>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include <list>


struct Node {
    Node(int value) : value{value} {}
    int value{0};
    std::shared_ptr<Node> left{nullptr};
    std::shared_ptr<Node> right{nullptr};
};

bool areSame(std::shared_ptr<Node> root1, std::shared_ptr<Node> root2) {
    if(root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if((root1 != nullptr && root2 == nullptr) || (root1 == nullptr && root2 != nullptr)) {
        return false;
    }
    return (root1->value == root2->value) && areSame(root1->left, root2->left) && areSame(root1->right, root2->right);
}

bool checkSubtree(std::shared_ptr<Node> root1, std::shared_ptr<Node> root2) {
    if(root1 == nullptr) {
        return false;
    }
    if(root1->value == root2->value) {
        auto same = areSame(root1, root2);
        if(same) {
            return true;
        }
    }
    return checkSubtree(root1->left, root2) || checkSubtree(root1->right, root2);
}

int main() {
    // Test 1
    {
        auto root1 = std::make_shared<Node>(2);
        auto a111 = std::make_shared<Node>(1);
        auto a112 = std::make_shared<Node>(3);
        root1->left = a111;
        root1->right = a112;

        auto root2 = std::make_shared<Node>(2);
        auto a211 = std::make_shared<Node>(1);
        auto a212 = std::make_shared<Node>(3);
        root2->left = a211;
        root2->right = a212;

        assert(true == checkSubtree(root1, root2));
    }

    // Test 2
    {
        auto root1 = std::make_shared<Node>(5);
        auto root11 = std::make_shared<Node>(2);
        auto a111 = std::make_shared<Node>(1);
        auto a112 = std::make_shared<Node>(3);
        root1->right = root11;
        root11->left = a111;
        root11->right = a112;

        auto root2 = std::make_shared<Node>(2);
        auto a211 = std::make_shared<Node>(1);
        auto a212 = std::make_shared<Node>(3);
        root2->left = a211;
        root2->right = a212;

        assert(true == checkSubtree(root1, root2));
    }

    return 0;
}
