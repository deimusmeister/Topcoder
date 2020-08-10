// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
// 
// 
// Given a word, you need to judge whether the usage of capitals in it is right or not.
// 
// We define the usage of capitals in a word to be right when one of the following cases holds:
// 
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 0) 
            return true;      
        auto capFound = isupper(word.front());
        if(capFound) {
            int count = 0;
            for(auto i : word) {
                if(isupper(i)) {
                    ++count;
                }
            }
            if (count == 1 || count == word.length())
                return true;
            else
                return false;
        } else {
            for(auto i : word) {
                if(isupper(i)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
