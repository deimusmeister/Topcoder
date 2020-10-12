// https://leetcode.com/problems/intersection-of-two-arrays/
// 
// Given two arrays, write a function to compute their intersection.
// 
// Example 1:
// 
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:
// 
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Note:
// 
// Each element in the result must be unique.
// The result can be in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result;
        std::unordered_set<int> mp; 
        for(auto i : nums1) {
            mp.insert(i);
        }
        for(auto i : nums2) {
            if(mp.find(i) != mp.end()) {
                result.push_back(i);
                mp.erase(i);
            }
        }
        return result;    
    }
};
