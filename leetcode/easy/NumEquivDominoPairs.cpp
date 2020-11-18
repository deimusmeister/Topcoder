// https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// 
// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.
// 
// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
// 
//  
// 
// Example 1:
// 
// Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
// Output: 1
//  
// 
// Constraints:
// 
// 1 <= dominoes.length <= 40000
// 1 <= dominoes[i][j] <= 9

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        std::unordered_map<std::string, int> mp;
        for(const auto& i : dominoes) {
            std::string key = "";
            if(i[0] > i[1]) {
                key = std::to_string(i[1]) + std::to_string(i[0]);
            } else {
                key = std::to_string(i[0]) + std::to_string(i[1]);
            }
            mp[key]++;
        }
        int count = 0;
        for(const auto& i : mp) {
            int n = i.second;
            n = (n * (n - 1)) / 2;
            count += n;
        }
        return count;
    }
};
