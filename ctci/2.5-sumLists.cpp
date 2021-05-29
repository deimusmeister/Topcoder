// 2.5 Sum Lists: 
// You have two numbers represented by a linked list, where each node contains a single digit.
// The digits are stored in reverse order, such that the 1 's digit is at the head of the list. 
// Write a function that adds the two numbers and returns the sum as a linked list.
// 
// EXAMPLE
// Input:(7-> 1 -> 6) + (5 -> 9 -> 2).Thatis,617 + 295. Output:2 -> 1 -> 9.Thatis,912.
// 
// FOLLOW UP
// Suppose the digits are stored in forward order. Repeat the above problem. EXAMPLE
// lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295. Output:9 -> 1 -> 2.Thatis,912.

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

std::shared_ptr<Node> sumList(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2){
    int carry = 0;
    std::shared_ptr<Node> head{nullptr};
    std::shared_ptr<Node> parent{nullptr};
    while(n1 != nullptr && n2 != nullptr) {
        auto result = std::make_shared<Node>((n1->value + n2->value + carry) % 10);
        if(n1->value + n2->value  + carry > 9) {
            carry = 1;
        } else {
            carry = 0;
        }
        n1 = n1->next;
        n2 = n2->next;
        if(parent) {
            parent->next = result;
        } else {
            parent = result;
            head = result;
        }
    }
    auto rem = (n1 == nullptr ? n2 : n1);
    while(rem != nullptr) {
        auto result = std::make_shared<Node>((rem->value + carry) % 10);
        if(rem->value + carry > 9) {
            carry = 1;
        } else {
            carry = 0;
        }
        rem = rem->next;
        if(parent) {
            parent->next = result;
        } else {
            parent = result;
            head = result;
        }        
    }
    if(carry == 1) {
        parent->next = std::make_shared<Node>(carry);
    }
    return head;
}

int main() {

    // Test 1
    {
        auto a1 = std::make_shared<Node>(1);
        auto b1 = std::make_shared<Node>(1);

        printNodes(a1);
        printNodes(b1);
        auto r = sumList(a1, b1);
        printNodes(r);
    }

    // Test 2
    {
        auto a1 = std::make_shared<Node>(9);
        auto b1 = std::make_shared<Node>(1);

        printNodes(a1);
        printNodes(b1);
        auto r = sumList(a1, b1);
        printNodes(r);
    }

    // Test 3
    {
        auto a1 = std::make_shared<Node>(9);
        auto a2 = std::make_shared<Node>(1);
        a1->next = a2;

        auto b1 = std::make_shared<Node>(9);
        auto b2 = std::make_shared<Node>(1);
        b1->next = b2;

        printNodes(a1);
        printNodes(b1);
        auto r = sumList(a1, b1);
        printNodes(r);
    }

    return 0;
}
