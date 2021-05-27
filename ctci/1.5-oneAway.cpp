// 1.5 One Away: 
// There are three types of edits that can be performed on strings: 
// insert a character, remove a character, or replace a character. 
// Given two strings, write a function to check if they are one edit (or zero edits) away.
// 
// EXAMPLE
// pale, ple -> true 
// pales, pale -> true 
// pale, bale -> true 
// pale, bake -> false

#include <iostream>
#include <string>
#include <unordered_map>

bool oneAway(const std::string& a, const std::string& b) {
    if(a.length() > 1 + b.length() || b.length() > 1 + a.length()) {
        return false;
    }
    std::string l;
    std::string s;
    if(a.length() > b.length()) {
        l = a;
        s = b;
    } else {
        l = b;
        s = a;
    }
    int p1 = 0;
    int p2 = 0;
    bool edit_detected{false};
    while(p1 != a.length() || p2 != b.length()) {
        if(a[p1] != b[p2]) {
            if(edit_detected) {
                return false;
            }
            edit_detected = true;
            if(a.length() == b.length()) {
                ++p1;
                ++p2;
            } else {
                ++p1;
            }
        } else {
            ++p1;
            ++p2;
        }
    }
    return true;
}

int main() {
    // "", ""
    assert(oneAway("", "") == true);

    // "pale", "ple"
    assert(oneAway("pale", "ple") == true);

    // "pales", "pale"
    assert(oneAway("pales", "pale") == true);

    // "pale", "bale"
    assert(oneAway("pale", "bale") == true);

    // "pale", "bake"
    assert(oneAway("pale", "bake") == false);

    // "pale", "bake"
    assert(oneAway("pale", "bake") == false);

    // "pale", "bakadsfasdfasdfe"
    assert(oneAway("pale", "bakadsfasdfasdfe") == false);

    return 0;
}
