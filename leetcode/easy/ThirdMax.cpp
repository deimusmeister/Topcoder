// https://leetcode.com/problems/third-maximum-number/
// 
// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
// 
// Example 1:
// Input: [3, 2, 1]
// 
// Output: 1
// 
// Explanation: The third maximum is 1.
// Example 2:
// Input: [1, 2]
// 
// Output: 2
// 
// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:
// Input: [2, 2, 3, 1]
// 
// Output: 1
// 
// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int64_t max1 = std::numeric_limits<int64_t>::min();
        int64_t max2 = std::numeric_limits<int64_t>::min();
        int64_t max3 = std::numeric_limits<int64_t>::min();
        for(int64_t i : nums) {
            max1 = std::max(max1, i);
        }
        for(int64_t i : nums) {
            if(i < max1) {
                max2 = std::max(max2, i);
            }
        }
        for(int64_t i : nums) {
            if(i < max2) {
                max3 = std::max(max3, i);
            }
        }
        if(max3 == std::numeric_limits<int64_t>::min()) {
            return max1;
        } else {
            return max3;
        }
    }
};
