// 2.6 Palindrome: 
// Implement a function to check if a linked list is a palindrome.

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

bool polindrome(std::shared_ptr<Node> node){
    std::shared_ptr<Node> p{nullptr};
    std::queue<int> q;
    while(node != nullptr) {
        q.push(node->value);
        auto t = node->next;
        node->next = p;
        p = node;
        node = t;
    }
    while(p != nullptr) {
        if(q.front() == p->value) {
            q.pop();
        }
        p = p->next;
    }
    return q.empty();
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

        printNodes(a1);
        assert(false == polindrome(a1));
    }

    // Test 2
    {
        auto a1 = std::make_shared<Node>(1);
        auto a2 = std::make_shared<Node>(1);
        auto a3 = std::make_shared<Node>(9);
        auto a4 = std::make_shared<Node>(1);
        auto a5 = std::make_shared<Node>(1);
        a1->next = a2;
        a2->next = a3;
        a3->next = a4;
        a4->next = a5;

        printNodes(a1);
        assert(true == polindrome(a1));
    }

    return 0;
}
