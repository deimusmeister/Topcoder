// 2.3 Delete Middle Node:
// Implement an algorithm to delete a node in the middle 
// (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, 
// given only access to that node.
// 
// EXAMPLE
// lnput:the node c from the linked lista->b->c->d->e->f
// Result: nothing is returned, but the new linked list looks likea->b->d->e- >f

#include <iostream>
#include <memory>

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

void deleteMiddleNode(std::shared_ptr<Node> head){
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return;
    } 
    auto slow = head;
    auto fast = head;

    // slows parent
    std::shared_ptr<Node> pslow;

    while(fast != nullptr) {
        if(fast->next != nullptr && fast->next != nullptr) {
            pslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        } else {
            break;
        }
    }
    if(pslow) {
        auto t = slow;
        slow = nullptr; // free memory
        pslow->next = t->next;
    }
}

int main() {

    // Test 1
    {
        auto n1 = std::make_shared<Node>(10);
        auto n2 = std::make_shared<Node>(14);
        auto n3 = std::make_shared<Node>(31);
        auto n4 = std::make_shared<Node>(761);
        auto n5 = std::make_shared<Node>(1245);
        auto n6 = std::make_shared<Node>(14);
        auto n7 = std::make_shared<Node>(31);
        auto n8 = std::make_shared<Node>(14);
        auto n9 = std::make_shared<Node>(343);
        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n5;
        n5->next = n6;
        n6->next = n7;
        n7->next = n8;
        n8->next = n9;

        printNodes(n1);
        deleteMiddleNode(n1);
        printNodes(n1);
    }

    // Test 2
    {
        auto n1 = std::make_shared<Node>(10);
        auto n2 = std::make_shared<Node>(14);
        auto n3 = std::make_shared<Node>(31);
        n1->next = n2;
        n2->next = n3;

        printNodes(n1);
        deleteMiddleNode(n1);
        printNodes(n1);
    }

    return 0;
}
