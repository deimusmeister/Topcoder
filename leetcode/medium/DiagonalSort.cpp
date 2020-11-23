// https://leetcode.com/problems/sort-the-matrix-diagonally/
// 
// Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.
// 
//  
// 
// Example 1:
// 
// 
// Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
// Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
//  
// 
// Constraints:
// 
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 100
// 1 <= mat[i][j] <= 100

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for(auto i : mat) {
            for(auto j : i) {
                pq.push(j);
            }
        }
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < std::max(n, m); ++i) {
            std::vector<int> d1;
            for(int j = 0; i + j < std::max(n, m); ++j) {
                if(j < n && i + j < m) {
                    auto t = mat[j][j + i];
                    d1.push_back(t);
                }
            }
            std::sort(d1.begin(), d1.end());
            for(int j = 0; i + j < std::max(m, n); ++j) {
                if(j < n && i + j < m) {
                    mat[j][j + i] = d1[j];
                }
            }
            
            std::vector<int> d2;
            for(int j = 0; j - i <= std::max(m, n); ++j) {
                if(j < n && j - i < m && j - i >= 0) {
                    auto t = mat[j][j - i];
                    d2.push_back(t);   
                }
            }
            std::sort(d2.begin(), d2.end());
            for(int j = 0; j - i <= std::max(m, n); ++j) {
                if(j < n && j - i < m && j - i >= 0) {
                    mat[j][j - i] = d2[j - i];
                }
            }
        }
        return mat;
    }
};
