// https://leetcode.com/problems/to-lower-case/
// 
// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
// 
//  
// 
// Example 1:
// 
// Input: "Hello"
// Output: "hello"
// Example 2:
// 
// Input: "here"
// Output: "here"
// Example 3:
// 
// Input: "LOVELY"
// Output: "lovely"

class Solution {
public:
    string toLowerCase(string str) {
        int offset = 'A' - 'a';
        for(auto& i : str) {
            if(i >= 'A' && i <= 'Z') {
                i -= offset;
            }
        }
        return str;
    }
};
