// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// 
// Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
// 
// Note:
// 
// All letters in hexadecimal (a-f) must be in lowercase.
// The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
// The given number is guaranteed to fit within the range of a 32-bit signed integer.
// You must not use any method provided by the library which converts/formats the number to hex directly.
// Example 1:
// 
// Input:
// 26
// 
// Output:
// "1a"
// Example 2:
// 
// Input:
// -1
// 
// Output:
// "ffffffff"

class Solution {
public:
    string toHex(int num) {
        if(num == 0) {
            return "0";
        }
        std::string result = "";
        bool neg = num < 0;
        bool first = true;
        int count = 0;
        while(num != 0 && count < 8) {
            int val = num % 16;
            if(val >= 10) {
                char t = 'a';
                t += (val - 10);
                result = t + result;
            } else if(val < 0) {
                if(first) {
                    first = false;
                    if('f' + val + 1 < 'a') {
                        result = std::to_string(15 + val + 1) + result;
                    } else {
                        result = char('f' + val + 1) + result;
                    }
                } else {
                    if('f' + val < 'a') {
                        result = std::to_string(15 + val) + result;
                    } else {
                        result = char('f' + val) + result;
                    }
                }
            } else {
                if(neg && val == 0 && !first) {
                    result = 'f' + result;   
                } else {
                    result = std::to_string(val) + result;   
                }
            }
            num = num - (num % 16);
            num = num / 16;
            ++count;
        }
        if(neg) {
            int n = result.length();
            result = std::string(8 - n, 'f') + result;
        }
        return result;
    }
};
