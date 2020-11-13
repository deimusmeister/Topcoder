// https://leetcode.com/problems/set-mismatch/
// 
// The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.
// 
// Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.
// 
// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]
// Note:
// The given array size will in the range [2, 10000].
// The given array's numbers won't have any order.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int missing = 0;
        int duplicate = 0;
        std::unordered_map<int, int> mp;
        for(int i = 1; i <= n; ++i) {
            mp[i] = true;
        }
        for(auto i : nums) {
            if(mp.find(i) != mp.end()) {
                if(mp[i]) {
                    mp[i] = false;   
                } else {
                    duplicate = i;
                }
            }
        }
        for(auto i : mp) {
            if(i.second) {
                missing = i.first;
            }
        }
        std::vector<int> result;
        result.push_back(duplicate);
        result.push_back(missing);
        return result;
    }
};
