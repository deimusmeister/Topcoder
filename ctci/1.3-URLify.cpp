// 1.3 URLify: 
// Write a method to replace all spaces in a string with '%20'. 
// You may assume that the string has sufficient space at the end to hold the additional characters,
// and that you are given the "true" length of the string. 
// 
// (Note: If implementing in Java,please use a character array so that you can perform this operation in place.)
// EXAMPLE
// Input: "Mr John Smith ", 13 Output: "Mr%20John%20Smith"

#include <iostream>
#include <string>

void URLify(std::string& str) {
    auto pos = str.begin();
    while(pos != str.end()) {
        if(*pos == ' ') {
            *pos = '%';
            str.insert(pos + 1, '2');
            str.insert(pos + 2, '0');
            pos = pos + 3;
        } else {
            ++pos;
        }
    }
}

int main() {
    // " "
    std::string s1 {" "};
    URLify(s1);
    assert(s1 == "%20");

    // ""
    std::string s2 {""};
    URLify(s2);
    assert(s2 == "");

    // " a b c "
    std::string s3 {" a b c "};
    URLify(s3);
    assert(s3 == "%20a%20b%20c%20");
   
    return 0;
}
