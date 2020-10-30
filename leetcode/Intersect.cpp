// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// 
// Given two arrays, write a function to compute their intersection.
// 
// Example 1:
// 
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:
// 
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Note:
// 
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
// Follow up:
// 
// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result;
        std::unordered_map<int, int> mp1;
        std::unordered_map<int, int> mp2;
        for(auto i : nums1) {
            mp1[i]++;
        }
        for(auto i : nums2) {
            mp2[i]++;
        }
        for(auto i : mp1) {
            if(mp2.find(i.first) != mp2.end()) {
                int n = std::min(i.second, mp2[i.first]);
                for(int k = 0; k < n; ++k) {
                    result.push_back(i.first);
                }
            }
        }
        return result;
    }
};
