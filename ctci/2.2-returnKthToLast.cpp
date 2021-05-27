// 2.2 Return Kth to Last: 
// Implement an algorithm to find the kth to last element of a singly linked list.

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

std::shared_ptr<Node> returnKthToLast(std::shared_ptr<Node> head, int k){
    if(head == nullptr || k < 0) {
        return nullptr;
    }
    auto p = head;
    auto c = head->next;

    // Set the new tail to nullptr
    p->next = nullptr;

    // Reverse singly linked list
    int count = 1;
    while(c != nullptr) {
        auto t = c->next;
        c->next = p;
        
        p = c;
        c = t;

        // track the legnth
        ++count;
    }

    if(count <= k) {
        return nullptr;
    }

    std::cout << "l = " << count << std::endl;
    while(p != nullptr && k != 0) {
        std::cout << p->value << " -> "; 
        p = p->next;
        --k;
    }
    std::cout << "nullptr" << std::endl;
    std::cout << "return value " << p->value << std::endl; 
    return p;
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

        auto t1 = returnKthToLast(n1, 2);
        assert(t1->value == 31);
    }

    // Test 2
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

        auto t2 = returnKthToLast(n1, 8);
        assert(t2->value == 10);
    }

    // Test 3
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

        auto t3 = returnKthToLast(n1, 9);
        assert(t3 == nullptr);
    }

    // Test 4
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

        auto t4 = returnKthToLast(n1, -2);
        assert(t4 == nullptr);
    }

    return 0;
}
