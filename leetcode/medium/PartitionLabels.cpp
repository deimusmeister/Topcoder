// https://leetcode.com/problems/partition-labels/
// 
// A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
// 
//  
// 
// Example 1:
// 
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
//  
// 
// Note:
// 
// S will have length in range [1, 500].
// S will consist of lowercase English letters ('a' to 'z') only.

class Solution {
public:
    vector<int> partitionLabels(string S) {
        std::unordered_map<char, std::pair<int, int>> mp;
        int n = S.length();
        int count = 0;
        for(auto i : S) {
            if(mp.find(i) == mp.end()) {
                mp[i].first = count;
            }
            mp[i].second = count;
            ++count;
        }
        std::vector<int> result;
        int start = mp[S[0]].first;
        int border = mp[S[0]].second;
        if(border == n - 1) {
            result.push_back(border - start + 1);
        }
        while(border != n - 1) {
            for(int i = start; i <= border; ++i) {
                auto t = mp[S[i]];
                border = std::max(border, t.second);
            }
            result.push_back(border - start + 1);
            if(border == n - 1) {
                break;
            }
            start = border + 1;
            border = mp[S[start]].second;
            if(border == n - 1) {
                result.push_back(border - start + 1);
                break;
            }
        }
        return result;
    }
};
