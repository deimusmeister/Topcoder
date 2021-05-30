// 3.2 Stack Min:
// How would you design a stack which, in addition to push and pop, 
// has a function min which returns the minimum element? 
// Push, pop and min should all operate in 0(1) time.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <optional>

template<typename T>
class Stack {
public:
    Stack(int storage_size) : storage_size(storage_size) {
        storage.resize(storage_size);
        min_storage.resize(storage_size);
    }
    bool push(T value) {
        if(cur_size >= storage_size) {
            return false;
        }
        ++cur_size;
        storage[cur_size - 1] = value;
        if(cur_size == 1) {
            min_storage[cur_size - 1] = value;
        } else {
            min_storage[cur_size - 1] = std::min(value, min_storage[cur_size - 2]);
        }
        return true;
    }
    std::optional<T> top() {
        std::optional<T> result;
        if(cur_size == 0) {
            return result;
        }
        result = storage[cur_size - 1];
        return result;
    }
    std::optional<T> min() {
        std::optional<T> result;
        if(cur_size == 0) {
            return result;
        }
        result = min_storage[cur_size - 1];
        return result;
    }
    bool is_empty() {
        return cur_size == 0;
    }
    bool pop() {
        if(cur_size == 0) {
            return false;
        }
        --cur_size;
        return true;
    }
private:
    std::vector<T> storage;
    std::vector<T> min_storage;
    size_t cur_size{0};
    size_t storage_size{0};
};

int main() {
    Stack<int> s(6);

    assert(true == s.push(4));
    assert(4 == s.min());
    assert(true == s.push(2));
    assert(2 == s.min());
    assert(true == s.push(3));
    assert(2 == s.min());
    assert(true == s.push(1));
    assert(1 == s.min());
    assert(true == s.push(5));
    assert(1 == s.min());
    assert(true == s.push(0));
    assert(0 == s.min());
    assert(false == s.push(1));

    assert(0 == s.top());

    assert(false == s.is_empty());

    assert(true == s.pop());
    assert(true == s.pop());
    assert(true == s.pop());
    assert(true == s.pop());
    assert(true == s.pop());
    assert(true == s.pop());
    assert(false == s.pop());

    assert(true == s.is_empty());
    
    assert(false == s.top().has_value());

    return 0;
}
