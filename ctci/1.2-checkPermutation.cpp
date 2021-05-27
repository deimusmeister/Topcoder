// 1.2 Check Permutation: 
// Given two strings, write a method to decide if one is a permutation of the other.

#include <iostream>
#include <unordered_map>

bool checkPermutation(const std::string& str1, const std::string& str2) {
    if(str1.empty() || str2.empty()) {
        return false;
    }
    std::unordered_map<char, int> m;
    for(const auto i : str1) {
        ++m[i];
    }
    for(const auto i : str2) {
        --m[i];
    }
    for(const auto& i : m) {
        if(i.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // "", ""
    assert(checkPermutation("", "") == false);

    // "abc", ""
    assert(checkPermutation("abc", "") == false);

    // "", "cde"
    assert(checkPermutation("", "cde") == false);

    // "abc", "cde"
    assert(checkPermutation("abc", "cde") == false);

    // "abc", "bca"
    assert(checkPermutation("abc", "bca") == true);
    
    return 0;
}
