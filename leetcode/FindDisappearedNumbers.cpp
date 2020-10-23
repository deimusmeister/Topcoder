// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// 
// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
// 
// Find all the elements of [1, n] inclusive that do not appear in this array.
// 
// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
// 
// Example:
// 
// Input:
// [4,3,2,7,8,2,3,1]
// 
// Output:
// [5,6]

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n);
        for(int i = 0; i < n; ++i) {
            result[i] = i + 1;
        }
        int count = 0;
        for(int i = 0; i < n; ++i) {
            auto j = nums[i] - 1;
            if(result[j] != n + 1) {
                result[j] = n + 1;
                count++;
            }
        }
        std::sort(result.begin(), result.end());
        result.erase(result.end() - count, result.end());
        return result;
    }
};
