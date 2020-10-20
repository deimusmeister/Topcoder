// https://leetcode.com/problems/valid-anagram/
// 
// Given two strings s and t , write a function to determine if t is an anagram of s.
// 
// Example 1:
// 
// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:
// 
// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.
// 
// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> mp;
        for(auto i : s) {
            if(mp.find(i) == mp.end()) {
                mp[i] = 1;
            } else {
                mp[i]++;
            }
        }
        for(auto i : t) {
            if(mp.find(i) == mp.end()) {
                return false;
            } else {
                mp[i]--;
            }
        }
        for(auto i : mp) {
            if(i.second != 0) {
                return false;
            }
        }
        return true;
    }
};
