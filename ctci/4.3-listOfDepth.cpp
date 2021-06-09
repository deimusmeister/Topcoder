// 4.3 List of Depths: 
// Given a binary tree, design an algorithm which creates a linked list of all the nodes
// at each depth (e.g., if you have a tree with depth 0, you'll have 0 linked lists).

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

struct ListNode {
    ListNode(std::shared_ptr<Node> value) : value(std::move(value)) {}

    std::shared_ptr<Node> value{nullptr};
    std::shared_ptr<ListNode> next{nullptr};
};

void visit(std::shared_ptr<Node> node, int depth, std::vector<std::shared_ptr<ListNode>>& result, std::vector<std::shared_ptr<ListNode>>& current) {
    if(node == nullptr) {
        return;
    }
    std::shared_ptr<ListNode> head = std::make_shared<ListNode>(node);
    if(result.size() < depth + 1) {
        result.push_back(head);
        current.push_back(head);
    } else {
        auto& tail = current[depth];
        tail->next = head;
        current[depth] = head;
    }
    visit(node->left, depth + 1, result, current);
    visit(node->right, depth + 1, result, current);
}

std::vector<std::shared_ptr<ListNode>> listOfDepth(std::shared_ptr<Node> root) {
    std::vector<std::shared_ptr<ListNode>> result;
    std::vector<std::shared_ptr<ListNode>> current;
    visit(root, 0, result, current);
    return result;
}

int main() {
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

    auto result = listOfDepth(root);
    std::cout << "number of list elements = " << result.size() << std::endl; 
    for(auto i : result) {
        while(i != nullptr) {
            std::cout << i->value->value << " -> ";
            i = i->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    return 0;
}
