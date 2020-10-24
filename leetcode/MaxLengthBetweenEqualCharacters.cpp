// https://leetcode.com/problems/largest-substring-between-two-equal-characters/
// 
// Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
// 
// A substring is a contiguous sequence of characters within a string.
// 
//  
// 
// Example 1:
// 
// Input: s = "aa"
// Output: 0
// Explanation: The optimal substring here is an empty substring between the two 'a's.
// Example 2:
// 
// Input: s = "abca"
// Output: 2
// Explanation: The optimal substring here is "bc".
// Example 3:
// 
// Input: s = "cbzxy"
// Output: -1
// Explanation: There are no characters that appear twice in s.
// Example 4:
// 
// Input: s = "cabbac"
// Output: 4
// Explanation: The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".
//  
// 
// Constraints:
// 
// 1 <= s.length <= 300
// s contains only lowercase English letters.

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        std::unordered_map<char, std::pair<int, int>> mp;
        for(int j = 0; j < s.length(); ++j) {
            auto i = s[j];
            if(mp.find(i) == mp.end()) {
                mp[i].first = j;
                mp[i].second = -1;
            } else {
                mp[i].second = j;
            }
        }
        int max = -1;
        for(auto i : mp) {
            auto val = i.second;
            if(val.second != -1) {
                max = std::max(max, val.second - val.first - 1);
            }
        }
        if(max == -1) {
            return -1;
        } else {
            return max;
        }
    }
};
