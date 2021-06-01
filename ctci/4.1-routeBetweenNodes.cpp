// 4.1 Route Between Nodes: 
// Given a directed graph, design an algorithm to find out whether there is a
// route between two nodes.

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <queue>

class Node {
public:
    Node(int value) : value(value) {}
    std::vector<std::shared_ptr<Node>> children;
    bool visited{false};
    int value{0};
};

bool searchDFS(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2) {
    if(n1.get() == n2.get()) {
        return true;
    }
    for(auto& i : n1->children) {
        if(!i->visited) {
            auto found = searchDFS(i, n2);
            i->visited = true;
            if(found) {
                return true;
            }
        }
    }
    return false;
}

bool searchBFS(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2) {
    std::queue<std::shared_ptr<Node>> q;
    q.push(n1);
    while(!q.empty()) {
        auto& top = q.front();
        if(top == n2) {
            return true;
        }
        q.pop();
        top->visited = true;
        for(auto& i : top->children) {
            if(!i->visited) {
                q.push(i);
            }
        }
    }
    return false;
}

int main() {
    // Test1
    {
        auto n1 = std::make_shared<Node>(1);
        auto n2 = std::make_shared<Node>(2);
        auto n3 = std::make_shared<Node>(3);
        auto n4 = std::make_shared<Node>(4);
        auto n5 = std::make_shared<Node>(5);
        auto n6 = std::make_shared<Node>(6);
        auto n7 = std::make_shared<Node>(7);
        n1->children = {n2, n3, n4, n5};
        n2->children = {n6, n7};

        // assert(true == searchDFS(n1, n5));
        assert(true == searchBFS(n1, n5));
    }
    
    {
        auto n1 = std::make_shared<Node>(1);
        auto n2 = std::make_shared<Node>(2);
        auto n3 = std::make_shared<Node>(3);
        auto n4 = std::make_shared<Node>(4);
        auto n5 = std::make_shared<Node>(5);
        auto n6 = std::make_shared<Node>(6);
        auto n7 = std::make_shared<Node>(7);
        n1->children = {n2, n3, n4, n5};
        n2->children = {n6, n7};

        // assert(true == searchDFS(n1, n7));
        assert(true == searchBFS(n1, n7));
    }

    {
        auto n1 = std::make_shared<Node>(1);
        auto n2 = std::make_shared<Node>(2);
        auto n3 = std::make_shared<Node>(3);
        auto n4 = std::make_shared<Node>(4);
        auto n5 = std::make_shared<Node>(5);
        auto n6 = std::make_shared<Node>(6);
        auto n7 = std::make_shared<Node>(7);
        auto n8 = std::make_shared<Node>(8);
        auto n9 = std::make_shared<Node>(9);
        n1->children = {n2, n3, n4, n5};
        n2->children = {n6, n7};
        n8->children = {n1, n5, n9};

        // assert(false == searchDFS(n1, n8));
        assert(false == searchBFS(n1, n8));
    }
    return 0;
}
