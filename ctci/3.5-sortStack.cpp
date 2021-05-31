// 3.5 Sort Stack: 
// Write a program to sort a stack such that the smallest items are on the top. You can use
// an additional temporary stack, but you may not copy the elements into any other data structure
// (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.

#include <iostream>
#include <vector>
#include <optional>
#include <cassert>
#include <stack>
#include <queue>

void sortStack(std::stack<int>& s) {
    if(s.empty()) {
        return;
    }
    int n = s.size();
    int sorted_length = 0;
    while(sorted_length != n -1) {
        std::stack<int> temp;
        int id = 0;
        int max = s.top();
        int cur = 0;
        while(s.size() != sorted_length) {
            if(max <= s.top()) {
                max = s.top();
                id = cur; 
            }
            ++cur;
            temp.push(s.top());
            s.pop();
        }
        s.push(max);
        cur = 0;
        auto n = temp.size();
        while(!temp.empty()) {
            if(cur != n - 1 - id) {
                s.push(temp.top());
                temp.pop();
            } else {
                temp.pop();
            }
            ++cur;
        }
        ++sorted_length;
    }
}

int main() {
    std::stack<int> s;
    s.push(45);
    s.push(21);
    s.push(43);
    s.push(42);
    s.push(85);
    s.push(5);
    s.push(75);
    sortStack(s);
    assert(5 == s.top());
    s.pop();
    assert(21 == s.top());
    s.pop();
    assert(42 == s.top());
    s.pop();
    assert(43 == s.top());
    s.pop();
    assert(45 == s.top());
    s.pop();
    assert(75 == s.top());
    s.pop();
    assert(85 == s.top());
    return 0;
}
