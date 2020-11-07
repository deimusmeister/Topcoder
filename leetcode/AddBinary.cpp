// https://leetcode.com/problems/add-binary/
// 
// Given two binary strings, return their sum (also a binary string).
// 
// The input strings are both non-empty and contains only characters 1 or 0.
// 
// Example 1:
// 
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
// 
// Input: a = "1010", b = "1011"
// Output: "10101"
//  
// 
// Constraints:
// 
// Each string consists only of '0' or '1' characters.
// 1 <= a.length, b.length <= 10^4
// Each string is either "0" or doesn't contain any leading zero.

class Solution {
public:
    string addBinary(string a, string b) {
        std::string result = "";
        int n1 = a.length();
        int n2 = b.length();
        int n = std::max(n1, n2);
        bool carry = false;
        for(int i = 0; i <= n - 1; ++i) {
            int t = 0;
            int v = 0;
            if(n1 - i - 1 >= 0) {
                t = a[n1 - 1 - i] - '0';
            }
            if(n2 - i - 1 >= 0) {
                v = b[n2 - 1 - i] - '0';
            }
            int r = t + v;
            if(carry) {
                r += 1;
            }
            carry = (r >= 2);
            if(r == 3) {
                result = "1" + result;
            } else if(r == 2) {
                result = "0" + result;
            } else {
                result = std::to_string(r) + result;
            }
        }
        if(carry) {
            result = "1" + result;
        }
        return result;
    }
};
