// https://leetcode.com/problems/search-insert-position
// 
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// 
//  
// 
// Example 1:
// 
// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:
// 
// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:
// 
// Input: nums = [1,3,5,6], target = 7
// Output: 4
// Example 4:
// 
// Input: nums = [1,3,5,6], target = 0
// Output: 0
// Example 5:
// 
// Input: nums = [1], target = 0
// Output: 0
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0;
        int end = n - 1;
        if(nums[beg] > target) {
            return 0;
        }
        if(nums[end] < target) {
            return end + 1;
        }
        int pos = beg + (end - beg) / 2;
        while(beg <= end) {
            if(end - beg == 1) {
                if(nums[end] == target) {
                    return end;
                } else if(nums[beg] == target) {
                    return beg;
                } else {
                    break;
                }
            }
            if(nums[pos] == target) {
                return pos;
            }
            if(nums[pos] < target) {
                beg = pos;
            } else {
                end = pos;
            }
            pos = beg + (end - beg) / 2;
        }
        if(nums[pos] > target) {
            if(pos == 0) {
                return pos;
            } else {
                return pos - 1;   
            }
        }
        if(target > nums[pos]) {
            return pos + 1;
        }
        return pos;
    }
};
