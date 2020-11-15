// https://leetcode.com/problems/contains-duplicate-ii/
// 
// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
// 
// Example 1:
// 
// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:
// 
// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:
// 
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, std::vector<int>> mp;
        for(int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].push_back(i);
        }
        for(const auto& i : mp) {
            int n = i.second.size();
            if(n > 1) {
                for(int j = 1; j < n; ++j) {
                    if(i.second[j] - i.second[j - 1] <= k) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
