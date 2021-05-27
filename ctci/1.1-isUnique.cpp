// 1.1 Is Unique: 
// Implement an algorithm to determine if a string has all unique characters. 
// What if you cannot use additional data structures?

#include <iostream>
#include <unordered_set>

bool isUnique(const std::string& str) {
    if(str.empty()) {
        return false;
    }
    std::unordered_set<char> m;
    for(const auto i : str) {
        if(m.find(i) != m.end()) {
            return false;
        }
        m.insert(i);
    }
    return true;
}

int main() {
    // s = ""
    assert(isUnique("") == false);

    // s = "abc"
    assert(isUnique("abc") == true);

    // s = "abcdefghijlll"
    assert(isUnique("abcdefghijlll") == false);
    
    return 0;
}
