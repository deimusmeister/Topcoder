// 2.1 Remove Dups!
// Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?

#include <iostream>
#include <memory>

class Node {
public:
    Node(int value) : value(value) {}
public:
    int value;
    std::shared_ptr<Node> next;
};

void removeDups(std::shared_ptr<Node> head) {
    auto p = head;
    while(p != nullptr) {
        auto cp = p;
        auto c = p->next;

        while(c != nullptr) {
            if(c->value != p->value) {
                cp->next = c;
                cp = c;
            }
            c = c->next;
        }
        if(cp == p) {
            p->next = nullptr;
            break;
        }
        p = p->next;
    }
}

void printNodes(std::shared_ptr<Node> head) {
    while(head != nullptr) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
    std::cout << "-----" << std::endl;
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
        removeDups(n1);
        printNodes(n1);
    }

    // Test 2
    {
        auto n1 = std::make_shared<Node>(10);
        auto n2 = std::make_shared<Node>(14);
        auto n3 = std::make_shared<Node>(14);
        auto n4 = std::make_shared<Node>(14);
        auto n5 = std::make_shared<Node>(14);
        auto n6 = std::make_shared<Node>(14);
        auto n7 = std::make_shared<Node>(14);
        auto n8 = std::make_shared<Node>(14);
        auto n9 = std::make_shared<Node>(14);
        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n5;
        n5->next = n6;
        n6->next = n7;
        n7->next = n8;
        n8->next = n9;

        printNodes(n1);
        removeDups(n1);
        printNodes(n1);
    }

    // Test 3
    {
        auto n1 = std::make_shared<Node>(14);
        auto n2 = std::make_shared<Node>(14);
        auto n3 = std::make_shared<Node>(14);
        auto n4 = std::make_shared<Node>(14);
        auto n5 = std::make_shared<Node>(14);
        auto n6 = std::make_shared<Node>(14);
        auto n7 = std::make_shared<Node>(14);
        auto n8 = std::make_shared<Node>(14);
        auto n9 = std::make_shared<Node>(14);
        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n5;
        n5->next = n6;
        n6->next = n7;
        n7->next = n8;
        n8->next = n9;

        printNodes(n1);
        removeDups(n1);
        printNodes(n1);
    }

    return 0;
}
