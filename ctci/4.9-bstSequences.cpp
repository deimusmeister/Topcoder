// 4.9 BST Sequences: 
// A binary search tree was created by traversing through an array from left to right
// and inserting each element. Given a binary search tree with distinct elements, print all possible
// arrays that could have led to this tree.
// EXAMPLE
// Input:
//          2
//         / \
//        1   3
// Output: {2, 1, 3}, {2, 3, 1}

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

void weave(std::list<int> first, std::list<int> second, std::vector<std::list<int>>& result, std::list<int> prefix) {
    if(first.empty() || second.empty()) {
        std::copy(first.begin(), first.end(), std::back_inserter(prefix));
        std::copy(second.begin(), second.end(), std::back_inserter(prefix));
        result.push_back(prefix);
        return;
    }

    // First
    auto ef = first.front();
    first.pop_front();
    prefix.push_back(ef);
    weave(first, second, result, prefix);
    
    // revert
    first.push_front(ef);
    prefix.pop_back();

    auto es = second.front();
    second.pop_front();
    prefix.push_back(es);
    weave(first, second, result, prefix);
    
    // // revert
    // second.insert(second.begin(), es);
    // prefix.pop_back();    
}

std::vector<std::list<int>> bstSequences(std::shared_ptr<Node> root) {
    std::vector<std::list<int>> result;
    if(root == nullptr) {
        result.push_back(std::list<int>());
        return result;
    }
    std::list<int> prefix = {root->value};
    auto left = bstSequences(root->left);
    auto right = bstSequences(root->right);

    for(auto l : left) {
        for(auto r : right) {
            std::vector<std::list<int>> weaved{};
            weave(l, r, weaved, prefix);
            std::copy(weaved.begin(), weaved.end(), std::back_inserter(result));
        }
    }

    return result;
}

int main() {
    // std::vector<std::vector<int>> result;
    // weave({1, 2}, {3, 4}, result, {});
    // for(auto i : result) {
    //     for(auto j : i) {
    //         std::cout << j << " "; 
    //     }
    //     std::cout << std::endl;
    // }

    // Test 1
    {
        auto root = std::make_shared<Node>(2);
        auto a11 = std::make_shared<Node>(1);
        auto a12 = std::make_shared<Node>(3);
        root->left = a11;
        root->right = a12;

        auto result = bstSequences(root);
        for(const auto& v : result) {
            for(auto i : v) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }

    // Test 2
    {
        auto root = std::make_shared<Node>(4);
        auto a11 = std::make_shared<Node>(2);
        auto a12 = std::make_shared<Node>(6);

        auto a21 = std::make_shared<Node>(1);
        auto a22 = std::make_shared<Node>(3);
        auto a23 = std::make_shared<Node>(5);
        auto a24 = std::make_shared<Node>(7);

        root->left = a11;
        root->right = a12;

        a11->left = a21;
        a11->right = a22;

        a12->left = a23;
        a12->right = a24;

        auto result = bstSequences(root);
        for(const auto& v : result) {
            for(auto i : v) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
