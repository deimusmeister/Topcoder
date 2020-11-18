// https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// 
// Given a rows x cols matrix mat, where mat[i][j] is either 0 or 1, return the number of special positions in mat.
// 
// A position (i,j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
// 
//  
// 
// Example 1:
// 
// Input: mat = [[1,0,0],
//               [0,0,1],
//               [1,0,0]]
// Output: 1
// Explanation: (1,2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
// Example 2:
// 
// Input: mat = [[1,0,0],
//               [0,1,0],
//               [0,0,1]]
// Output: 3
// Explanation: (0,0), (1,1) and (2,2) are special positions. 
// Example 3:
// 
// Input: mat = [[0,0,0,1],
//               [1,0,0,0],
//               [0,1,1,0],
//               [0,0,0,0]]
// Output: 2
// Example 4:
// 
// Input: mat = [[0,0,0,0,0],
//               [1,0,0,0,0],
//               [0,1,0,0,0],
//               [0,0,1,0,0],
//               [0,0,0,1,1]]
// Output: 3
//  
// 
// Constraints:
// 
// rows == mat.length
// cols == mat[i].length
// 1 <= rows, cols <= 100
// mat[i][j] is 0 or 1.


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] != 1) {
                    continue;
                }
                bool foundHorizontal = false;
                bool foundVertical = false;
                for(int k = 0; k < n; ++k) {
                    if(mat[k][j] == 1) {
                        if(foundVertical) {
                            foundVertical = false;
                            break;
                        } else {
                            foundVertical = true;
                        }
                    }
                }
                for(int k = 0; k < m; ++k) {
                    if(mat[i][k] == 1) {
                        if(foundHorizontal) {
                            foundHorizontal = false;
                            break;
                        } else {
                            foundHorizontal = true;
                        }
                    }
                }
                if(foundVertical && foundHorizontal) {
                    ++count;
                }
            }
        }
        return count;
    }
};
