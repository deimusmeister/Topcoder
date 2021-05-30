// 2.7 Intersection: 
// Given two (singly) linked lists, determine if the two lists intersect. 
// Return the inter­secting node. Note that the intersection is defined based on reference, not value.
// That is, if the kth node of the first linked list is the exact same node (by reference) as the jth 
// node of the second linked list, then they are intersecting.

#include <iostream>
#include <memory>
#include <queue>

class Node {
public:
    Node(int value) : value(value) {}
public:
    int value;
    std::shared_ptr<Node> next;
};

void printNodes(std::shared_ptr<Node> head) {
    while(head != nullptr) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
    std::cout << "-----" << std::endl;
}

std::shared_ptr<Node> intersection(std::shared_ptr<Node> a1, std::shared_ptr<Node> b1){
    int n1 = 0;
    int n2 = 0;
    auto t = a1;
    while(t != nullptr) {
        t = t->next;
        ++n1;
    }

    // Reverse b1 linked list
    std::shared_ptr<Node> p{nullptr};
    auto tb = b1;
    while(tb != nullptr) {
        auto t = tb->next;
        tb->next = p;
        p = b1;
        tb = t;
        ++n2;
    }

    bool does_intersect{false};
    t = a1;
    p = nullptr;
    int n_merged{0};
    while(t != nullptr) {
        ++n_merged;
        p = t;
        t = t->next;
    }
    if(p != b1) {
        return nullptr;
    }
    int k = n1 - (n1 + n2 - n_merged + 1) / 2;
    while(k != 0) {
        a1 = a1->next;
        --k;
    }
    return a1;
}

int main() {

    // Test 1
    {
        auto a1 = std::make_shared<Node>(2);
        auto a2 = std::make_shared<Node>(1);
        auto a3 = std::make_shared<Node>(9);
        auto a4 = std::make_shared<Node>(1);
        auto a5 = std::make_shared<Node>(1);
        a1->next = a2;
        a2->next = a3;
        a3->next = a4;
        a4->next = a5;

        auto b1 = std::make_shared<Node>(4);
        auto b2 = std::make_shared<Node>(41);
        b1->next = b2;
        b2->next = a3;

        printNodes(a1);
        printNodes(b1);
        assert(a3 == intersection(a1, b1));
    }

    // Test 2
    {
        auto a1 = std::make_shared<Node>(2);
        auto a2 = std::make_shared<Node>(1);
        auto a3 = std::make_shared<Node>(9);
        auto a4 = std::make_shared<Node>(1);
        auto a5 = std::make_shared<Node>(1);
        a1->next = a2;
        a2->next = a3;
        a3->next = a4;
        a4->next = a5;

        auto b1 = std::make_shared<Node>(4);
        auto b2 = std::make_shared<Node>(41);
        b1->next = b2;

        printNodes(a1);
        printNodes(b1);
        assert(nullptr == intersection(a1, b1));
    }

    return 0;
}
