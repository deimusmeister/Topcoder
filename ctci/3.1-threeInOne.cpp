// 3.1 Three in One:
// Describe how you could use a single array to implement three stacks.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <optional>

template<typename T>
class Stack {
public:
    Stack(int storage_size) : storage_size(storage_size) {
        storage.resize(3 * storage_size);
    }
    bool push(T value, int index) {
        if(index != 0 && index != 1 && index != 2) {
            return false;
        }
        auto offset = index * storage_size + info[index];
        if(offset >= index * storage_size + storage_size) {
            return false;
        }
        ++info[index];
        storage[offset] = value;
        return true;
    }
    std::optional<T> top(int index) {
        std::optional<T> value;
        if(info.find(index) == info.end()) {
            // std::cout << __func__ << " empty" << std::endl;
            return value;
        }
        auto offset = index * storage_size + info[index];
        value = storage[offset - 1];
        // std::cout << __func__ << " offset = " << offset << ", value = " << value.value() << std::endl;
        return value;
    }
    bool is_empty(int index) {
        return info.find(index) == info.end();
    }
    bool pop(int index) {
        if(info.find(index) == info.end()) {
            return false;
        }
        --info[index];
        if(info[index] == 0) {
            info.erase(index);
        }
        return true;
    }
private:
    std::vector<T> storage;
    std::unordered_map<int, int> info;
    int storage_size{0};
};

int main() {
    Stack<int> s(3);

    assert(true == s.push(1, 0));
    assert(true == s.push(2, 0));
    assert(true == s.push(3, 0));
    assert(false == s.push(1, 0));

    assert(3 == s.top(0));

    assert(false == s.is_empty(0));

    assert(true == s.pop(0));
    assert(true == s.pop(0));
    assert(true == s.pop(0));
    assert(false == s.pop(0));

    assert(true == s.is_empty(0));
    
    assert(false == s.top(0).has_value());

    return 0;
}
