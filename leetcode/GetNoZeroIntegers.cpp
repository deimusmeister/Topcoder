// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
// 
// Given an integer n. No-Zero integer is a positive integer which doesn't contain any 0 in its decimal representation.
// 
// Return a list of two integers [A, B] where:
// 
// A and B are No-Zero integers.
// A + B = n
// It's guarateed that there is at least one valid solution. If there are many valid solutions you can return any of them.
// 
//  
// 
// Example 1:
// 
// Input: n = 2
// Output: [1,1]
// Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.
// Example 2:
// 
// Input: n = 11
// Output: [2,9]
// Example 3:
// 
// Input: n = 10000
// Output: [1,9999]
// Example 4:
// 
// Input: n = 69
// Output: [1,68]
// Example 5:
// 
// Input: n = 1010
// Output: [11,999]
//  
// 
// Constraints:
// 
// 2 <= n <= 10^4

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n - a;
        while(a <= n) {
            auto ta = a;
            auto tb = b;

            while(ta != 0) {
                if(ta % 10 == 0) {
                    break;
                }
                ta = ta / 10;
            }
            while(tb != 0) {
                if(tb % 10 == 0) {
                    break;
                }
                tb = tb / 10;
            }
            if(ta == 0 && tb == 0) {
                break;
            } else {
                a++;
                b = n - a;
            }
        }
        return {a, b};
    }
};
