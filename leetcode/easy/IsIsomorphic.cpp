// https://leetcode.com/problems/isomorphic-strings/
// 
// Given two strings s and t, determine if they are isomorphic.
// 
// Two strings are isomorphic if the characters in s can be replaced to get t.
// 
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
// 
// Example 1:
// 
// Input: s = "egg", t = "add"
// Output: true
// Example 2:
// 
// Input: s = "foo", t = "bar"
// Output: false
// Example 3:
// 
// Input: s = "paper", t = "title"
// Output: true
// Note:
// You may assume both s and t have the same length.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if(n1 != n2) {
            return false;
        }
        std::vector<int> fp1;
        std::unordered_map<char, int> mp1;
        int count = 0;
        for(auto i : s) {
            if(mp1.find(i) == mp1.end()) {
                mp1[i] = count;
                ++count;
            }
            fp1.push_back(mp1[i]);
        }
        
        std::vector<int> fp2;
        std::unordered_map<char, int> mp2;
        count = 0;
        for(auto i : t) {
            if(mp2.find(i) == mp2.end()) {
                mp2[i] = count;
                ++count;
            }
            fp2.push_back(mp2[i]);
        }
        
        for(int i = 0; i < n1; ++i) {
            if(fp1[i] != fp2[i]) {
                return false;
            }
        }
        return true;
    }
};
