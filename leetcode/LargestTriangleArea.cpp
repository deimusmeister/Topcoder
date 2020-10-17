// https://leetcode.com/problems/largest-triangle-area/
// 
// You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.
// 
// Example:
// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2
// Explanation: 
// The five points are show in the figure below. The red triangle is the largest.
// 
// 
// Notes:
// 
// 3 <= points.length <= 50.
// No points will be duplicated.
//  -50 <= points[i][j] <= 50.
// Answers within 10^-6 of the true value will be accepted as correct.

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double max = 0;
        int n = p.size();
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    int ax = p[i][0] - p[j][0];
                    int ay = p[i][1] - p[j][1];
                    double a = std::sqrt((ax * ax) + (ay * ay));
                    
                    int bx = p[k][0] - p[j][0];
                    int by = p[k][1] - p[j][1];
                    double b = std::sqrt((bx * bx) + (by * by));
                    
                    int cx = p[k][0] - p[i][0];
                    int cy = p[k][1] - p[i][1];
                    double c = std::sqrt((cx * cx) + (cy * cy));
                    
                    double hp = (a + b + c) / 2;
                    auto area = std::sqrt(hp * (hp - a) * (hp - b) * (hp - c));
                    max = std::max(max, area);
                }
            }
        }
        return max;
    }
};
