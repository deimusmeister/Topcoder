// https://leetcode.com/problems/surface-area-of-3d-shapes/
// 
// On a N * N grid, we place some 1 * 1 * 1 cubes.
// 
// Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
// 
// Return the total surface area of the resulting shapes.
// 
//  
// 
// Example 1:
// 
// Input: [[2]]
// Output: 10
// Example 2:
// 
// Input: [[1,2],[3,4]]
// Output: 34
// Example 3:
// 
// Input: [[1,0],[0,2]]
// Output: 16
// Example 4:
// 
// Input: [[1,1,1],[1,0,1],[1,1,1]]
// Output: 32
// Example 5:
// 
// Input: [[2,2,2],[2,1,2],[2,2,2]]
// Output: 46
//  
// 
// Note:
// 
// 1 <= N <= 50
0 <= grid[i][j] <= 50

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) {
                    continue;
                }
                
                sum += 1; // top
                sum += 1; //bottom
                
                // up
                if(i >= 1) {
                    auto diff = grid[i][j] - grid[i - 1][j];
                    if(diff > 0) {
                        sum += diff;
                    }
                } else if(i == 0) {
                    sum += grid[i][j];
                }
                
                // down
                if(i + 1 < n) {
                    auto diff = grid[i][j] - grid[i + 1][j];
                    if(diff > 0) {
                        sum += diff;
                    }
                } else if(i == n - 1) {
                    sum += grid[i][j];
                }
                
                // left
                if(j >= 1) {
                    auto diff = grid[i][j] - grid[i][j - 1];
                    if(diff > 0) {
                        sum += diff;
                    }
                } else if(j == 0) {
                    sum += grid[i][j];
                }
                
                // right
                if(j + 1 < n) {
                    auto diff = grid[i][j] - grid[i][j + 1];
                    if(diff > 0) {
                        sum += diff;
                    }
                } else if(j == n - 1) {
                    sum += grid[i][j];
                }
            }
        }
        return sum;
    }
};
