// 3.3 Stack of Plates: 
// Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
// Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
// threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
// composed of several stacks and should create a new stack once the previous one exceeds capacity.
// SetOfStacks. push () and SetOfStacks. pop () should behave identically to a single stack
// (that is, pop ( ) should return the same values as it would if there were just a single stack).
// FOLLOW UP
// Implement a function popAt (int index) which performs a pop operation on a specific sub-stack.

#include <iostream>
#include <vector>
#include <optional>
#include <cassert>

class SetOfStacks {
public:
    SetOfStacks(int capacity) : capacity(capacity) { }

    void push(int value) {
        if(s.empty()) {
            std::vector<int> v;
            s.push_back(v);
        }
        auto& v = s.back();
        if(v.size() >= capacity) {
            std::vector<int> nv(1, value);
            s.push_back(nv);
        } else {
            v.push_back(value);
        }
    }

    bool pop() {
        if(s.empty()) {
            return false;
        }
        auto& v = s.back();
        v.pop_back();
        if(v.empty()) {
            s.pop_back();
        }
        return true;
    }

    std::optional<int> top() {
        std::optional<int> result;
        if(s.empty()) {
            return result;
        }
        auto v = s.back();
        result = v.back();
        return result;
    }

    void printInfo() {
        std::cout << "The current number of stacks = " << s.size() << std::endl;
        if(!s.empty()) {
            std::cout << "The size of the last stack = " << s.back().size() << std::endl;
        }
    }
private:
    int capacity{0};
    std::vector<std::vector<int>> s;
};

int main() {
    SetOfStacks s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.printInfo();
    assert(4 == s.top());

    assert(true == s.pop());
    assert(true == s.pop());
    assert(true == s.pop());
    assert(true == s.pop());
    assert(false == s.pop());

    return 0;
}
