// https://leetcode.com/problems/greatest-common-divisor-of-strings/
// 
// For two strings s and t, we say "t divides s" if and only if s = t + ... + t  (t concatenated with itself 1 or more times)
// 
// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
// 
//  
// 
// Example 1:
// 
// Input: str1 = "ABCABC", str2 = "ABC"
// Output: "ABC"
// Example 2:
// 
// Input: str1 = "ABABAB", str2 = "ABAB"
// Output: "AB"
// Example 3:
// 
// Input: str1 = "LEET", str2 = "CODE"
// Output: ""
// Example 4:
// 
// Input: str1 = "ABCDEF", str2 = "ABC"
// Output: ""
//  
// 
// Constraints:
// 
// 1 <= str1.length <= 1000
// 1 <= str2.length <= 1000
// str1 and str2 consist of English uppercase letters.

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        std::string result = "";
        int a = std::max(str1.length(), str2.length());
        int b = std::min(str1.length(), str2.length());
        while(b != 0) {
            auto t = b;
            b = a % b;
            a = t;
        }
        //     function gcd(a, b)
        // while b ≠ 0
        //     t := b
        //     b := a mod b
        //     a := t
        // return a
        std::unordered_map<char, int> mp1;
        std::unordered_map<char, int> mp2;
        for(auto i : str1) {
            mp1[i]++;
        }
        for(auto i : str2) {
            mp2[i]++;
        }
        if(mp1.size() != mp2.size()) {
            return "";
        }
        int min1 = std::numeric_limits<int>::max();
        int ln1 = 0;
        for(auto i : mp1) {
            min1 = std::min(min1, i.second);
        }
        for(auto i : mp1) {
            ln1 += i.second / min1;
        }

        int min2 = std::numeric_limits<int>::max();
        int ln2 = 0;
        for(auto i : mp2) {
            min2 = std::min(min2, i.second);
        }
        for(auto i : mp2) {
            ln2 += i.second / min2;
        }
        if(ln2 != ln1) {
            return "";
        }
        if(str1.substr(0, a) != str2.substr(0, a)) {
            return "";
        }
        result = str1.substr(0, a);   
        return result;
    }
};
