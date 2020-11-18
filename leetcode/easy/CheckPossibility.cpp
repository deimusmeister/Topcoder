// https://leetcode.com/problems/non-decreasing-array/
// 
// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
// 
// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
// 
//  
// 
// Example 1:
// 
// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
// Example 2:
// 
// Input: nums = [4,2,1]
// Output: false
// Explanation: You can't get a non-decreasing array by modify at most one element.
//  
// 
// Constraints:
// 
// 1 <= n <= 10 ^ 4
// - 10 ^ 5 <= nums[i] <= 10 ^ 5

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int pivot = -1;
        for(int i = 1; i < n; ++i) {
            if(nums[i - 1] > nums[i]) {
                pivot = i;
                ++count;
            }
        }
        if(count == 0) {
            return true;
        }
        if(count > 1) {
            return false;
        }
        int count1 = 0;
        if(pivot - 2 >= 0) {
            for(int i = pivot - 2; i >= 0; --i) {
                if(nums[i] > nums[pivot]) {
                    count1++;
                }
            }   
        }
        int count2 = 0;
        if(pivot + 1 < n) {
            for(int i = pivot - 1; i >= 0; --i) {
                if(nums[i] > nums[pivot + 1]) {
                    count2++;
                }
            }
        }
        if(count1 > 0 && count2 > 0) {
            return false;
        }
        return true;
    }
};
