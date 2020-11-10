// https://leetcode.com/problems/repeated-substring-pattern/
// 
// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
// 
// Example 1:
// 
// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.
// Example 2:
// 
// Input: "aba"
// Output: False
// Example 3:
// 
// Input: "abcabcabcabc"
// Output: True
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        std::string result = "";
        for(int i = 1; i < n / 2 + 1; ++i) {
            result = s.substr(i, n - i) + s.substr(0, i);
            if(result == s) {
                return true;
            }
        }
        return false;
    }
};
