
// 1. 9 String Rotation:
// Assume you have a method isSubstringwhich checks if one word is a substring of another. 
// Given two strings, s1 and s2, write code to check if s2 is a rotation of sl using only one call to isSubstring 
// (e.g.,"waterbottle" is a rotation of "erbottlewat").

#include <iostream>
#include <string>

bool isSubstringwhich(std::string a, std::string b) {
    return a.find(b) != std::string::npos || b.find(a) != std::string::npos;
} 

bool stringRotation(std::string s1, std::string s2) {
    std::string s = s1 + s1;
    return isSubstringwhich(s, s2);
}

int main() {
    // "waterbottle", "erbottlewat"
    assert(stringRotation("waterbottle", "erbottlewat") == true);

    // "waterbottle", "erbottleasdfasdfawat"
    assert(stringRotation("waterbottle", "erboafttleasdfasdfawat") == false);

    return 0;
}
