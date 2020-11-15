// https://leetcode.com/problems/word-pattern/
// 
// Given a pattern and a string s, find if s follows the same pattern.
// 
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
// 
//  
// 
// Example 1:
// 
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:
// 
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:
// 
// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
// Example 4:
// 
// Input: pattern = "abba", s = "dog dog dog dog"
// Output: false
//  
// 
// Constraints:
// 
// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lower-case English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int count = 0;
        std::unordered_map<char, int> mp;
        std::vector<int> pt1;
        for(auto i : pattern) {
            if(mp.find(i) == mp.end()) {
                mp[i] = ++count;
            }
            pt1.push_back(mp[i]);
        }
        
        count = 0;
        std::unordered_map<std::string, int> mp1;
        std::vector<int> pt2;
        std::string cur = "";
        for(auto i : s) {
            if(i != ' ') {
                cur += i;
            } else {
                if(mp1.find(cur) == mp1.end()) {
                    mp1[cur] = ++count;
                }
                pt2.push_back(mp1[cur]);
                cur = "";
            }
        }
        if(!cur.empty()) {
            if(mp1.find(cur) == mp1.end()) {
                mp1[cur] = ++count;
            }
            pt2.push_back(mp1[cur]);
        }
        
        if(pt1.size() != pt2.size()) {
            return false;
        } else {
            for(int i = 0; i < pt1.size(); ++i) {
                if(pt1[i] != pt2[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
