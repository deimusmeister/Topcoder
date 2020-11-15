// https://leetcode.com/problems/reverse-integer/
// 
// Given a 32-bit signed integer, reverse digits of an integer.
// 
// Note:
// Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
// 
//  
// 
// Example 1:
// 
// Input: x = 123
// Output: 321
// Example 2:
// 
// Input: x = -123
// Output: -321
// Example 3:
// 
// Input: x = 120
// Output: 21
// Example 4:
// 
// Input: x = 0
// Output: 0
//  
// 
// Constraints:
// 
// -231 <= x <= 231 - 1

class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x == std::numeric_limits<int>::min()) {
            return 0;
        }
        if(x < 0) {
            x *= -1;
            neg = true;
        }
        int64_t rev = 0;
        while(x != 0) {
            auto t = x % 10;
            x /= 10;
            
            rev *= 10;
            rev += t;
        }
        if(rev > std::numeric_limits<int>::max()) {
            return 0;
        } else {
            int ret = static_cast<int>(rev);
            if(neg) {
                ret *= (-1);
            }
            return ret;
        }
    }
};
