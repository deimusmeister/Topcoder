// https://leetcode.com/problems/backspace-string-compare/
// 
// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
// 
// Note that after backspacing an empty text, the text will continue empty.
// 
// Example 1:
// 
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:
// 
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:
// 
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:
// 
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:
// 
// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        std::string str1 = "";
        std::string str2 = "";
        for(auto i : S) {
            if(i == '#') {
                if(!str1.empty()) {
                    str1.pop_back();   
                }
            } else {
                str1.push_back(i);   
            }
        }
        for(auto i : T) {
            if(i == '#') {
                if(!str2.empty()) {
                    str2.pop_back();   
                }
            } else {
                str2.push_back(i);   
            }
        }
        return str2 == str1;
    }
};
