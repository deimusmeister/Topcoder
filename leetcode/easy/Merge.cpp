// https://leetcode.com/problems/merge-sorted-array/
// 
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
// 
// Note:
// 
// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
// Example:
// 
// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
// 
// Output: [1,2,2,3,5,6]
//  
// 
// Constraints:
// 
// -10^9 <= nums1[i], nums2[i] <= 10^9
// nums1.length == m + n
// nums2.length == n

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = 0;
        int pos2 = 0;
        std::vector<int> result;
        while(pos1 < m && pos2 < n) {
            if(nums1[pos1] < nums2[pos2]) {
                result.push_back(nums1[pos1]);
                pos1++;
            } else {
                result.push_back(nums2[pos2]);
                pos2++;
            }
        }
        while(pos1 < m) {
            result.push_back(nums1[pos1]);
            pos1++;
        }
        while(pos2 < n) {
            result.push_back(nums2[pos2]);
            pos2++;
        }
        for(int i = 0; i < m + n; ++i) {
            nums1[i] = result[i];
        }
    }
};
