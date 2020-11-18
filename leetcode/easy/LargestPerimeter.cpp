// https://leetcode.com/problems/largest-perimeter-triangle/
// 
// Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.
// 
// If it is impossible to form any triangle of non-zero area, return 0.
// 
// Example 1:
// 
// Input: [2,1,2]
// Output: 5
// Example 2:
// 
// Input: [1,2,1]
// Output: 0
// Example 3:
// 
// Input: [3,2,3,4]
// Output: 10
// Example 4:
// 
// Input: [3,6,2,3]
// Output: 8
//  
// 
// Note:
// 
// 3 <= A.length <= 10000
// 1 <= A[i] <= 10^6

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if(A.size() < 3) {
            return 0;
        }
        std::sort(A.begin(), A.end(), std::greater<>());
        for(int i = 0; i < A.size() - 2; ++i) {
            auto a = A[i];
            auto b = A[i + 1];
            auto c = A[i + 2];
            if (a + b > c && a + c > b && b + c > a) {
                return a + b + c;
            }
        }
        return 0;
    }
};
