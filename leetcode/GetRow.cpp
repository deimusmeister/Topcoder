// https://leetcode.com/problems/pascals-triangle-ii/
// 
// Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
// 
// Notice that the row index starts from 0.
// 
// 
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
// 
// Follow up:
// 
// Could you optimize your algorithm to use only O(k) extra space?
// 
//  
// 
// Example 1:
// 
// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:
// 
// Input: rowIndex = 0
// Output: [1]
// Example 3:
// 
// Input: rowIndex = 1
// Output: [1,1]
//  
// 
// Constraints:
// 
// 0 <= rowIndex <= 40

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> row;
        int count = 0;
        row.push_back(1); 
        if(count == rowIndex) {
            return row;
        }
        ++count;
        row.push_back(1);
        if(count == rowIndex) {
            return row;
        }
        while(count != rowIndex) {
            ++count;
            std::vector<int> newVec;
            newVec.push_back(1);
            for(int i = 1; i < row.size(); ++i) {
                newVec.push_back(row[i - 1] + row[i]);
            }
            newVec.push_back(1);
            row = newVec;
        }
        return row;
    }
};
