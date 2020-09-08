// https://leetcode.com/problems/lucky-numbers-in-a-matrix/
// 
// Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
// 
// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
// 
//  
// 
// Example 1:
// 
// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
// Example 2:
// 
// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// Output: [12]
// Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
// Example 3:
// 
// Input: matrix = [[7,8],[1,2]]
// Output: [7]
//  
// 
// Constraints:
// 
// m == mat.length
// n == mat[i].length
// 1 <= n, m <= 50
// 1 <= matrix[i][j] <= 10^5.
// All elements in the matrix are distinct.

class Solution {
public:
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int,int> & v) const {
            return v.first*31+v.second;
        }
    };
    
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        auto m = matrix.size();
        auto n = matrix[0].size();
        
        std::unordered_set<std::pair<int, int>, pair_hash> rowMins;
        for(auto i = 0; i < m; ++i) {
            auto minRow = matrix[i][0];
            auto minRowId = 0;
            for(auto j = 0; j < n; ++j) {
                if(matrix[i][j] < minRow) {
                    minRow = matrix[i][j];
                    minRowId = j;
                }
            }
            rowMins.insert(std::make_pair(i, minRowId));
        }
        
        std::unordered_set<std::pair<int, int>, pair_hash> colMaxs;
        for(auto i = 0; i < n; ++i) {
            auto maxCol = matrix[0][i];
            auto maxColId = 0;
            for(auto j = 0; j < m; ++j) {
                if(matrix[j][i] > maxCol) {
                    maxCol = matrix[j][i];
                    maxColId = j;
                }
            }
            colMaxs.insert(std::make_pair(maxColId, i));
        }
        std::vector<int> result;
        for(auto i : rowMins) {
            if(colMaxs.find(i) != colMaxs.end()) {
                result.push_back(matrix[i.first][i.second]);
            }
        }
        return result;
    }
};
