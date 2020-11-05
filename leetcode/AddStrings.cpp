// https://leetcode.com/problems/add-strings/
// 
// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
// 
// Note:
// 
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

class Solution {
public:
    string addStrings(string num1, string num2) {
        std::string result;
        int pos1 = num1.length() - 1;
        int pos2 = num2.length() - 1;
        bool carry = false;
        while(pos1 >= 0 || pos2 >= 0) {
            int a = 0;
            if(pos1 >= 0) {
                a = num1[pos1] - '0';
            }
            int b = 0;
            if(pos2 >= 0) {
                b = num2[pos2] - '0';
            }
            int c = a + b;
            if(carry) {
                c++;
            }
            carry = c >= 10;
            result = std::to_string(c % 10) + result;
            pos1--;
            pos2--;
        }
        if(carry) {
            result = "1" + result;
        }
        return result;
    }
};
