// https://leetcode.com/problems/image-smoother/
// 
// Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.
// 
// Example 1:
// Input:
// [[1,1,1],
//  [1,0,1],
//  [1,1,1]]
// Output:
// [[0, 0, 0],
//  [0, 0, 0],
//  [0, 0, 0]]
// Explanation:
// For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
// For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
// For the point (1,1): floor(8/9) = floor(0.88888889) = 0
// Note:
// The value in the given matrix is in the range of [0, 255].
// The length and width of the given matrix are in the range of [1, 150].

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        std::vector<std::vector<int>> result;
        int n = M.size();
        int m = M[0].size();   
        for(int i = 0; i < n; ++i) {
            std::vector<int> row;
            for(int j = 0; j < m; ++j) {
                int sum = 0;
                int count = 0;
                int t = 0;
                t = getValue(M, i - 1, j - 1);
                if(t < std::numeric_limits<int>::max()) {
                    ++count;
                    sum += t;
                }
                t = getValue(M, i - 1, j);
                if(t < std::numeric_limits<int>::max()) {
                    ++count;
                    sum += t;
                }
                t = getValue(M, i - 1, j + 1);
                if(t < std::numeric_limits<int>::max()) {
                    ++count;
                    sum += t;
                }
                t = getValue(M, i, j - 1);
                if(t < std::numeric_limits<int>::max()) {
                    ++count;
                    sum += t;
                }
                t = getValue(M, i, j);
                if(t < std::numeric_limits<int>::max()) {
                    ++count;
                    sum += t;
                }
                t = getValue(M, i, j + 1);
                if(t < std::numeric_limits<int>::max()) {
                    ++count;
                    sum += t;
                }
                t = getValue(M, i + 1, j - 1);
                if(t < std::numeric_limits<int>::max()) {
                    ++count;
                    sum += t;
                }
                t = getValue(M, i + 1, j);
                if(t < std::numeric_limits<int>::max()) {
                    ++count;
                    sum += t;
                }
                t = getValue(M, i + 1, j + 1);
                if(t < std::numeric_limits<int>::max()) {
                    ++count;
                    sum += t;
                }
                int val = std::floor(sum / count);
                row.push_back(val);
            }
            result.push_back(row);
        }
        return result;
    }
    int getValue(const vector<vector<int>>& M, int x, int y) {
        int n = M.size();
        int m = M[0].size();       
        if(x >= 0 && y >= 0 && x < n && y < m) {
            return M[x][y];
        } else {
            return std::numeric_limits<int>::max();
        }
    }
};
