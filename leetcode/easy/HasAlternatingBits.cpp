// https://leetcode.com/problems/binary-number-with-alternating-bits/
// 
// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
// 
//  
// 
// Example 1:
// 
// Input: n = 5
// Output: true
// Explanation: The binary representation of 5 is: 101
// Example 2:
// 
// Input: n = 7
// Output: false
// Explanation: The binary representation of 7 is: 111.
// Example 3:
// 
// Input: n = 11
// Output: false
// Explanation: The binary representation of 11 is: 1011.
// Example 4:
// 
// Input: n = 10
// Output: true
// Explanation: The binary representation of 10 is: 1010.
// Example 5:
// 
// Input: n = 3
// Output: false
//  
// 
// Constraints:
// 
// 1 <= n <= 231 - 1

class Solution {
public:
    bool hasAlternatingBits(int n) {
        uint64_t t = n >> 1;
        uint64_t v = (t + n) & (t + n + 1);
        return v == 0;
    }
    
    // bool hasAlternatingBits(int n) {
    //     bool found = n & 0x1;
    //     n = n >> 1;
    //     while(n != 0) {
    //         if(found && n & 0x1) {
    //             return false;
    //         }
    //         if(!found && !(n & 0x1)) {
    //             return false;
    //         }
    //         found = n & 0x01;
    //         n = n >> 1;
    //     }
    //     return true;
    // }
};
