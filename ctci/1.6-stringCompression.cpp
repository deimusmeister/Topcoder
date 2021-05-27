// 1.6 String Compression: 
// Implement a method to perform basic string compression using the counts of repeated characters. 
// For example, the string aabcccccaaa would become a2b1c5a3. 
// If the "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include <iostream>
#include <string>
#include <unordered_map>

std::string stringCompression(const std::string& a) {
    if(a.empty() || a.length() == 1) {
        return a;
    }
    std::string result;
    int count = 1;
    for(int i = 1; i < a.length(); ++i) {
        if(a[i] == a[i - 1]) {
            ++count;
        } else {
            result.append(1, a[i - 1]);
            result.append(std::to_string(count));
            count = 1;
        }
    }
    result.append(1, a.back());
    result.append(std::to_string(count));
    if(result.length() < a.length()) {
        return result;
    } else {
        return a;
    }
}

int main() {
    // ""
    assert(stringCompression("") == "");

    // "a"
    assert(stringCompression("a") == "a");

    // "ab"
    assert(stringCompression("ab") == "ab");

    // "aaabb"
    assert(stringCompression("aaabb") == "a3b2");

    return 0;
}
