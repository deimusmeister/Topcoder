// https://leetcode.com/problems/flower-planting-with-no-adjacent/
// 
// You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes the existence of a bidirectional path from garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.
// 
// There is no garden that has more than three paths coming into or leaving it.
// 
// Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.
// 
// Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.
// 
//  
// 
// Example 1:
// 
// Input: n = 3, paths = [[1,2],[2,3],[3,1]]
// Output: [1,2,3]
// Example 2:
// 
// Input: n = 4, paths = [[1,2],[3,4]]
// Output: [1,2,1,2]
// Example 3:
// 
// Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
// Output: [1,2,3,4]


class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        int flowers = 4;
        std::unordered_map<int, std::vector<int>> mp;
        std::vector<int> result(n);
        for(auto i : paths) {
            auto source = i[0];
            auto dest = i[1];
            mp[source].push_back(dest);
            mp[dest].push_back(source);
        }
        for(int i = 0; i < n; ++i) {
            auto garden = i + 1;
            std::vector<int> pallet{1, 2, 3, 4};
            for(auto j : mp[garden]) {
                auto color = result[j - 1];
                if(color != 0) {
                    pallet[color - 1] = 0;    
                }
            }
            for(auto j : pallet) {
                if(j != 0) {
                    result[garden - 1] = j;
                    break;
                }
            }
        }
        return result;
    }
};
