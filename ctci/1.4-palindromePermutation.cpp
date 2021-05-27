// 1.4 Palindrome Permutation:
// Given a string, write a function to check if it is a permutation of a palin­drome. 
// A palindrome is a word or phrase that is the same forwards and backwards. 
// A permutation is a rearrangement of letters. 
// The palindrome does not need to be limited to just dictionary words.
// EXAMPLE
// Input: Tact Coa
// Output: True (permutations: "taco cat", "atco eta", etc.)


#include <iostream>
#include <string>
#include <unordered_map>

bool palindromePermutation(const std::string& str) {
    if(str.empty()) {
        return false;
    }
    std::unordered_map<char, int> m;
    for(auto i : str) {
        if(i != ' ') {
            ++m[std::tolower(i)];
        }
    }
    bool odd_found{false};
    if(m.empty()) {
        return false;
    }
    for(auto i : m) {
        if(i.second % 2) {
            if(!odd_found) {
                odd_found = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // ""
    assert(palindromePermutation("") == false);

    // "   "
    assert(palindromePermutation("   ") == false);

    // "aba "
    assert(palindromePermutation("aba ") == true);

    // "aaa b b   "
    assert(palindromePermutation("aba ") == true);

    // "Tact Coa"
    assert(palindromePermutation("Tact Coa") == true);

    return 0;
}
