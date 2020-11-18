// https://leetcode.com/problems/maximum-average-subarray-i/
// 
// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
// 
// Example 1:
// 
// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
//  
// 
// Note:
// 
// 1 <= k <= n <= 30,000.
// Elements of the given array will be in the range [-10,000, 10,000].

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double max = std::numeric_limits<double>::lowest();
        
        int sum = 0;
        for(int j = 0; j < k; ++j) {
            sum += nums[j];
        }
        
        for(int i = 0; i <= n - k; ++i) {
            if(i > 0) {
                sum -= nums[i - 1];
                sum += nums[k + i - 1];
            }
            double aver = static_cast<double>(sum) / static_cast<double>(k);
            max = std::max(aver, max);
        }
        return max;
    }
};
