// https://leetcode.com/problems/power-of-three/
// 
// Given an integer n, return true if it is a power of three. Otherwise, return false.
// 
// An integer n is a power of three, if there exists an integer x such that n == 3x.
// 
//  
// 
// Example 1:
// 
// Input: n = 27
// Output: true
// Example 2:
// 
// Input: n = 0
// Output: false
// Example 3:
// 
// Input: n = 9
// Output: true
// Example 4:
// 
// Input: n = 45
// Output: false
//  
// 
// Constraints:
// 
// -231 <= n <= 231 - 1
//  
// 
// Follow up: Could you do it without using any loop / recursion?

class Solution {
public:
     bool isPowerOfThree(int n) {
        if(n <= 0) {
            return false;
        }
        if(n == 1) {
            return true;
        } 
        int64_t max = 1;
        while(max < std::numeric_limits<int>::max()) {
            max *= 3;
        }
        return max % n == 0;
    }
    // bool isPowerOfThree(int n) {
    //     bool result = true;
    //     if(n == 0) {
    //         return false;
    //     }
    //     if(n == 1) {
    //         return result;
    //     }
    //     while(n != 1) {
    //         if(n % 3 != 0) {
    //             result = false;
    //             break;
    //         }
    //         n = n / 3;
    //     }
    //     return result;
    // }
};
