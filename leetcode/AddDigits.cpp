// https://leetcode.com/problems/add-digits/
// 
// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
// 
// Example:
// 
// Input: 38
// Output: 2 
// Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
//              Since 2 has only one digit, return it.
// Follow up:
// Could you do it without any loop/recursion in O(1) runtime?

class Solution {
public:
    int addDigits(int num) {
        while(num / 10 != 0) {
            auto t = num;
            int newN = 0;
            while(t != 0) {
                newN += (t % 10);
                t = t / 10;
            }
            num = newN;
        }
        return num;
    }
};
