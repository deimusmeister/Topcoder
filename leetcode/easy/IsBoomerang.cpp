// https://leetcode.com/problems/valid-boomerang/
// 
// A boomerang is a set of 3 points that are all distinct and not in a straight line.
// 
// Given a list of three points in the plane, return whether these points are a boomerang.
// 
//  
// 
// Example 1:
// 
// Input: [[1,1],[2,3],[3,2]]
// Output: true
// Example 2:
// 
// Input: [[1,1],[2,2],[3,3]]
// Output: false
//  
// 
// Note:
// 
// points.length == 3
// points[i].length == 2
// 0 <= points[i][j] <= 100

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        auto a = points[0];
        auto b = points[1];
        auto c = points[2];
        
        auto t1 = (b[1] - a[1]) * (c[0] - a[0]);
        auto t2 = (b[0] - a[0]) * (c[1] - a[1]);

        return t1 != t2;
    }
};
