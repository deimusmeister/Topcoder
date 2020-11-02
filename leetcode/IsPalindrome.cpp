// https://leetcode.com/problems/palindrome-number/
// 
// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
// 
// Follow up: Could you solve it without converting the integer to a string?
// 
//  
// 
// Example 1:
// 
// Input: x = 121
// Output: true
// Example 2:
// 
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:
// 
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Example 4:
// 
// Input: x = -101
// Output: false
//  
// 
// Constraints:
// 
// -231 <= x <= 231 - 1

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        std::vector<int> mp;
        while(x != 0) {
            auto t = x % 10;
            mp.push_back(t);
            x = x / 10;
        }
        int n = mp.size();
        for(int i = 0; i < n / 2; ++i) {
            if(mp[i] != mp[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
