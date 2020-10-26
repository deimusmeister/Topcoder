// https://leetcode.com/problems/binary-search/
// 
// Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
// 
// 
// Example 1:
// 
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// 
// Example 2:
// 
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
//  
// 
// Note:
// 
// You may assume that all elements in nums are unique.
// n will be in the range [1, 10000].
// The value of each element in nums will be in the range [-9999, 9999].

class Solution {
public:
    int search(vector<int>& nums, int target) {
        visit(nums, 0, nums.size() - 1, target);
        return result;
    }
    void visit(std::vector<int>& nums, int start, int end, int target) {
        if(start == end) {
            if(nums[start] == target) {
                result = start;
            }
            return;
        } else if(start < end) {
            int middle  = (end - start) / 2;
            if(middle != 0) {
                if(nums[start + middle] == target) {
                    result = start + middle;
                    return;
                } else if(nums[start + middle] < target) {
                    visit(nums, start + middle, end, target);
                } else {
                    visit(nums, start, start + middle, target);    
                }
            } else if(std::abs(start - end) == 1) {
                visit(nums, start, start, target);
                visit(nums, end, end, target);
            }
        } else {
            return;
        }
    }
private:
    int result{-1};
};
