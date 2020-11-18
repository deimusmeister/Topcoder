// https://leetcode.com/problems/number-of-boomerangs/
// 
// Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
// 
// Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
// 
// Example:
// 
// Input:
// [[0,0],[1,0],[2,0]]
// 
// Output:
// 2
// 
// Explanation:
// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count = 0;
        int n = points.size();
        for(int i = 0; i < n; ++i) {
            std::unordered_map<int, int> mp;
            for(int j = 0; j < n; ++j) {
                if(i == j) {
                    continue;
                }
                int dx = std::pow(points[i][0] - points[j][0], 2);
                int dy = std::pow(points[i][1] - points[j][1], 2);
                mp[dx + dy]++;
            }
            for(const auto& i : mp) {
                count += i.second * (i.second - 1);
            }
        }
        return count;
    }
    // int numberOfBoomerangs(vector<vector<int>>& points) {
    //     int n = points.size();
    //     int count = 0;
    //     for(int i = 0; i < n; ++i) {
    //         for(int j = 0; j < n; ++j) {
    //             for(int k = j + 1; k < n; ++k) {
    //                 auto ei = points[i];
    //                 auto ej = points[j];
    //                 auto ek = points[k];
    //                 int dij = (ei[0] - ej[0]) * (ei[0] - ej[0]) + (ei[1] - ej[1]) * (ei[1] - ej[1]);
    //                 int dik = (ei[0] - ek[0]) * (ei[0] - ek[0]) + (ei[1] - ek[1]) * (ei[1] - ek[1]);
    //                 if(dij == dik) {
    //                     ++count;
    //                 }
    //             }
    //         }
    //     }
    //     return 2 * count;
    // }
};
