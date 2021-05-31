// 3.4 Queue via Stacks:
// Implement a MyQueue class which implements a queue using two stacks.

#include <iostream>
#include <vector>
#include <optional>
#include <cassert>
#include <stack>
#include <queue>

class MyQueue {
public:
    MyQueue(int size) : size(size) { }
    std::optional<int> front() {
        std::optional<int> result;
        if(main.empty()) {
            return result;
        }
        while(!main.empty()) {
            temp.push(main.top());
            main.pop();
        }
        result = temp.top();
        while(!temp.empty()) {
            main.push(temp.top());
            temp.pop();
        }
        return result;
    }
    bool push(int value) {
        if(main.size() == size) {
            return false;
        }
        main.push(value);
        return true;
    }
    bool pop() {
        if(main.empty()) {
            return false;
        }
        while(!main.empty()) {
            temp.push(main.top());
            main.pop();
        }
        temp.pop();
        while(!temp.empty()) {
            main.push(temp.top());
            temp.pop();
        }
        return !main.empty();
    }
private:
    int size{0};
    std::stack<int> main;
    std::stack<int> temp;
};

int main() {
    MyQueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    assert(true == q.push(5));
    assert(false == q.push(6));

    assert(1 == q.front());
    assert(true == q.pop());
    assert(2 == q.front());
    assert(true == q.pop());
    assert(true == q.pop());
    assert(true == q.pop());
    assert(false == q.pop());

    return 0;
}
