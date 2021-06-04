// 4.2 Minimal Tree: 
// Given a sorted (increasing order) array with unique integer elements, write an
// algorithm to create a binary search tree with minimal height.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <optional>

class Node {
public:
    Node(int value) : value(value) {}
    int value{0};
    std::shared_ptr<Node> left{nullptr};
    std::shared_ptr<Node> right{nullptr};
};

void printInOrder(std::shared_ptr<Node> root) {
    if(root == nullptr) {
        return;
    }
    printInOrder(root->left);
    std::cout << root->value << " ";
    printInOrder(root->right);
}

void createBST(std::vector<int>& v, int start, int end, std::shared_ptr<Node>& root) {
    if(v.empty()) {
        return;
    }
    if(start > end || start < 0 || end >= v.size()) {
        return;
    }
    if(start == end) {
        root = std::make_shared<Node>(v[start]);
        return;
    }
    int mid = (start + end) / 2;
    if((start + end) % 2 == 1) {
        mid++;
    }
    root = std::make_shared<Node>(v[mid]);
    createBST(v, start, mid - 1, root->left);
    createBST(v, mid + 1, end, root->right);
}

int main() {
    std::shared_ptr<Node> root{nullptr};

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    createBST(v, 0, v.size() - 1, root);

    // Test 1
    for(auto i : v) {
        std::cout << i << " "; 
    }
    std::cout << std::endl;
    std::cout << "-------" << std::endl;
    printInOrder(root);
    std::cout << std::endl;

    return 0;
}
