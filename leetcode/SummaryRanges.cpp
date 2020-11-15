// https://leetcode.com/problems/summary-ranges/
// 
// You are given a sorted unique integer array nums.
// 
// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
// 
// Each range [a,b] in the list should be output as:
// 
// "a->b" if a != b
// "a" if a == b
//  
// 
// Example 1:
// 
// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: The ranges are:
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"
// Example 2:
// 
// Input: nums = [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: The ranges are:
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"
// Example 3:
// 
// Input: nums = []
// Output: []
// Example 4:
// 
// Input: nums = [-1]
// Output: ["-1"]
// Example 5:
// 
// Input: nums = [0]
// Output: ["0"]
//  
// 
// Constraints:
// 
// 0 <= nums.length <= 20
// -231 <= nums[i] <= 231 - 1
// All the values of nums are unique.
// nums is sorted in ascending order.

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> result;
        int n = nums.size();
        if(n == 0) {
            return result;
        }
        if(n == 1) {
            result.push_back(std::to_string(nums[0]));
            return result;
        }
        int pos = 0;
        for(int i = 1; i < n; ++i) {
            if(nums[i] != nums[i - 1] + 1) {
                std::string en = "";
                if(i - pos == 1) {
                    en = std::to_string(nums[pos]);   
                } else {
                    en = std::to_string(nums[pos]) + "->" + std::to_string(nums[i - 1]);   
                }
                pos = i;
                result.push_back(en);
            }
        }
        std::string en = "";
        if(pos == n - 1) {
            en = std::to_string(nums[pos]);   
        } else {
            en = std::to_string(nums[pos]) + "->" + std::to_string(nums[n - 1]);   
        }
        result.push_back(en);
        return result;
    }
};
