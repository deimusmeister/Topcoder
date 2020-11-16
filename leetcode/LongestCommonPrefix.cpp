// https://leetcode.com/problems/longest-common-prefix/
// 
// Write a function to find the longest common prefix string amongst an array of strings.
// 
// If there is no common prefix, return an empty string "".
// 
//  
// 
// Example 1:
// 
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:
// 
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//  
// 
// Constraints:
// 
// 0 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) {
            return "";
        }
        if(n == 1) {
            return strs[0];
        }
        auto sample = strs[0];
        int pos = sample.length();
        for(auto i = 1; i < n; ++i) {
            auto t = strs[i];
            int count = 0;
            for(int j = 0; j < t.length(); ++j) {
                if(t[j] == sample[j]) {
                    ++count;
                } else {
                    break;
                }
            }
            pos = std::min(pos, count);
        }
        return sample.substr(0, pos);
    }
};
