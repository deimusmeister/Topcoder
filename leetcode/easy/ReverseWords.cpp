// https://leetcode.com/problems/reverse-words-in-a-string-iii/
// 
// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// 
// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Note: In the string, each word is separated by single space and there will not be any extra space in the string.

class Solution {
public:
    string reverseWords(string s) {
        std::string result = "";
        std::string tmp = "";
        for(auto i : s) {
            if(i != ' ') {
                tmp = i + tmp;
            } else {
                result = result + tmp + " ";
                tmp = "";
            }
        }
        if(tmp != "") {
            result = result + tmp;
        }
        return result;
    }
};
