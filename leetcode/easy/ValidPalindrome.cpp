// https://leetcode.com/problems/valid-palindrome-ii/
// 
// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
// 
// Example 1:
// Input: "aba"
// Output: True
// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int b = 0;
        int e = n - 1;
        int count = 0;
        while(b < e) {
            if(s[b] != s[e]) {
                ++count;
                if(s[b + 1] == s[e] && s[b] == s[e - 1]) {
                    b++;
                    --e;
                    --count;
                } else if(s[b + 1] == s[e]) {
                    b++;
                } else if(s[b] == s[e - 1]){
                    --e;
                } else {
                    return false;
                }
                if(count > 1) {
                    return false;
                }
            } else {
                b++;
                --e;
            }
        }
        return true;
    }
};
