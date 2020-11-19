// https://leetcode.com/problems/longest-repeating-character-replacement/
// 
// Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.
// 
// In one operation, you can choose any character of the string and change it to any other uppercase English character.
// 
// Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.
// 
// Note:
// Both the string's length and k will not exceed 104.
// 
// Example 1:
// 
// Input:
// s = "ABAB", k = 2
// 
// Output:
// 4
// 
// Explanation:
// Replace the two 'A's with two 'B's or vice versa.
//  
// 
// Example 2:
// 
// Input:
// s = "AABABBA", k = 1
// 
// Output:
// 4
// 
// Explanation:
// Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if(n == 1 || n == 0) {
            return n;
        }
        std::unordered_map<char, std::vector<std::pair<int, int>>> mp;
        char c = s[0];
        int start = 0;
        int count = 0;
        int id = 0;
        for(auto i : s) {
            if(c == i) {
                ++count;
            } else {
                mp[c].push_back(std::pair(start, count));
                count = 1;
                start = id; 
                c = i;
            }
            ++id;
        }
        mp[c].push_back(std::pair(start, count));
        
        int max = 0;
        for(auto i : mp) {
            for(int p = 0; p < i.second.size(); ++p) {
                int len = i.second[p].second;
                int lastId = i.second[p].first + i.second[p].second - 1;
                max = std::max(max, len);
                int m = k;
                for(int j = p + 1; j < i.second.size(); ++j) {
                    auto nstartId = i.second[j].first;
                    auto nlen = i.second[j].second;
                    max = std::max(max, nlen);

                    int delta = nstartId - lastId - 1;
                    if(delta <= m) {
                        m -= delta;
                        len += delta + nlen;
                        lastId = nstartId + nlen - 1;
                    } else {
                        len += m;
                        if(len > n) {
                            len = n;
                        }
                        max = std::max(max, len);
                        m = 0;
                        break;
                    }
                }
                if(m != 0) {
                    len += m;
                    if(len > n) {
                        len = n;
                    }
                    max = std::max(max, len);
                    m = 0;
                }
                max = std::max(max, len);
            }
        }
        return max;
    }
};
