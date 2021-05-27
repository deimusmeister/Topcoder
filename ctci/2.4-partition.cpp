// 2.4 Partition: 
// Write code to partition a linked list around a value x, 
// such that all nodes less than x come before all nodes greater than or equal to x. 
// 
// If x is contained within the list, the values of x only need to be after the elements less than x (see below). 
// The partition element x can appear anywhere in the "right partition"; 
// it does not need to appear between the left and right partitions.
// 
// EXAMPLE
// Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1[partition=5] Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

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

void partition(std::shared_ptr<Node> node, int value){
    if(node == nullptr) {
        return;
    }
    auto pivot = node;
    while(node != nullptr) {
        if(node->value < value) {
            std::swap(node->value, pivot->value);
            pivot = pivot->next;
        }
        node = node->next;
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
        partition(n1, 31);
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
        partition(n1, 31);
        printNodes(n1);
    }

    return 0;
}
