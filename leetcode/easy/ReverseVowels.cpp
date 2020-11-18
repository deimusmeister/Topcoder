// https://leetcode.com/problems/reverse-vowels-of-a-string/
// 
// Write a function that takes a string as input and reverse only the vowels of a string.
// 
// Example 1:
// 
// Input: "hello"
// Output: "holle"
// Example 2:
// 
// Input: "leetcode"
// Output: "leotcede"
// Note:
// The vowels does not include the letter "y".

class Solution {
public:
    string reverseVowels(string s) {
        std::string vowels = "";
        for(auto u : s) {
            char i = std::tolower(u);
            if(i == 'a' || i == 'o' || i == 'e' || i == 'i' || i == 'u') {
                vowels = u + vowels;
            }
        }
        std::string result = "";
        int pos = 0;
        for(auto u : s) {
            char i = std::tolower(u);
            if(i == 'a' || i == 'o' || i == 'e' || i == 'i' || i == 'u') {
                result += vowels[pos++];
            } else {
                result += u;
            }
        }
        return result;
    }
};
