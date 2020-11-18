// https://leetcode.com/problems/valid-palindrome/
// 
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// 
// Note: For the purpose of this problem, we define empty string as valid palindrome.
// 
// Example 1:
// 
// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:
// 
// Input: "race a car"
// Output: false
//  
// 
// Constraints:
// 
// s consists only of printable ASCII characters.

class Solution {
public:
    bool isPalindrome(string s) {
        std::string result = "";
        for(auto i : s) {
            if(i >= 'A' && i <= 'Z') {
                result += std::tolower(i);
            }
            if(i >= 'a' && i <= 'z') {
                result += i;
            }
            if(i >= '0' && i <= '9') {
                result += i;
            }
        }
        int n = result.length();
        for(int i = 0; i < n / 2; ++i) {
            if(result[i] != result[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
