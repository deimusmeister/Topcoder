// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// 
// Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.
// 
// Return that integer.
// 
//  
// 
// Example 1:
// 
// Input: arr = [1,2,2,6,6,6,6,7,10]
// Output: 6
//  
// 
// Constraints:
// 
// 1 <= arr.length <= 10^4
// 0 <= arr[i] <= 10^5

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        std::unordered_map<int, int> mp;
        int n = arr.size();
        for(auto i : arr) {
            if(mp.find(i) == mp.end()) {
                mp[i] = 1;
            } else {
                mp[i]++;
            }
            if(mp[i] * 4 > n) {
                return i;
            }
        }
        return 0;
    }
};
