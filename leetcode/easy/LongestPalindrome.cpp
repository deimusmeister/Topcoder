// https://leetcode.com/problems/longest-palindrome/
// 
// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
// 
// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
// 
//  
// 
// Example 1:
// 
// Input: s = "abccccdd"
// Output: 7
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:
// 
// Input: s = "a"
// Output: 1
// Example 3:
// 
// Input: s = "bb"
// Output: 2
//  
// 
// Constraints:
// 
// 1 <= s.length <= 2000
// s consits of lower-case and/or upper-case English letters only.


class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> mp;
        for(auto i : s) {
            mp[i]++;
        }
        int result = 0;
        bool hasOdd = false;
        for(const auto& i : mp) {
            result += i.second / 2;
            if(!hasOdd && i.second % 2 == 1) {
                hasOdd = true;
            }
        }
        result = 2 * result;
        if(hasOdd || (result == 0 && mp.size() >= 1)) {
            result += 1;
        }
        return result;
    }
};
