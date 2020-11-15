// https://leetcode.com/problems/factorial-trailing-zeroes/
// 
// Given an integer n, return the number of trailing zeroes in n!.
// 
// Follow up: Could you write a solution that works in logarithmic time complexity?
// 
//  
// 
// Example 1:
// 
// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:
// 
// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Example 3:
// 
// Input: n = 0
// Output: 0
//  
// 
// Constraints:
// 
// 1 <= n <= 104

class Solution {
public:
    int trailingZeroes(int n) {
        int k5 = 0;
        for(int i = 1; i <= n; ++i) {
            auto t = i;
            while(t % 5 == 0) {
                ++k5;
                t /= 5;
            }
        }
        return k5;
    }
};
