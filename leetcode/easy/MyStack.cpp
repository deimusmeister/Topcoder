// https://leetcode.com/problems/implement-stack-using-queues/
// 
// Implement a last in first out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).
// 
// Implement the MyStack class:
// 
// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:
// 
// You must use only standard operations of a queue, which means only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue), as long as you use only a queue's standard operations.
// Follow-up: Can you implement the stack such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        std::deque<int> mp;
        while(!q.empty() && q.size() != 1) {
            auto t = q.front();
            mp.push_back(t);
            q.pop_front();
        }
        auto top = q.front();
        q.pop_front();
        q = mp;
        return top;
    }
    
    /** Get the top element. */
    int top() {
        std::deque<int> mp;
        while(!q.empty() && q.size() != 1) {
            auto t = q.front();
            mp.push_back(t);
            q.pop_front();
        }
        auto top = q.front();
        mp.push_back(top);
        q.pop_front();
        q = mp;
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size() == 0;
    }
private:
    std::deque<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
