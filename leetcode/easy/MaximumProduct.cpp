// https://leetcode.com/problems/maximum-product-of-three-numbers/
// 
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
// 
//  
// 
// Example 1:
// 
// Input: nums = [1,2,3]
// Output: 6
// Example 2:
// 
// Input: nums = [1,2,3,4]
// Output: 24
// Example 3:
// 
// Input: nums = [-1,-2,-3]
// Output: -6
//  
// 
// Constraints:
// 
// 3 <= nums.length <= 104
// -1000 <= nums[i] <= 1000

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        int e = nums[n - 1];
        int f = nums[n - 2];
        int g = nums[n - 3];
        int max = a * b * c;
        if(n == 3) {
            return max;
        } else {
            max = std::max(max, a * b * e);
            max = std::max(max, e * f * a);
            max = std::max(max, e * f * g);
        }
        return max;
    }
};
