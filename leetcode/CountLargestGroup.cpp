// https://leetcode.com/problems/count-largest-group/
// 
// Given an integer n. Each number from 1 to n is grouped according to the sum of its digits. 
// 
// Return how many groups have the largest size.
// 
//  
// 
// Example 1:
// 
// Input: n = 13
// Output: 4
// Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
// [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.
// Example 2:
// 
// Input: n = 2
// Output: 2
// Explanation: There are 2 groups [1], [2] of size 1.
// Example 3:
// 
// Input: n = 15
// Output: 6
// Example 4:
// 
// Input: n = 24
// Output: 5

class Solution {
public:
    int countLargestGroup(int n) {
        std::unordered_map<int, std::vector<int>> map;
        int max = 0;
        for(int i = 1; i <= n; ++i) {
            auto t = i;
            int sum = 0;
            while(t != 0) {
                sum += (t % 10);
                t = t / 10;
            }
            map[sum].push_back(i);
            auto size = map[sum].size();
            max = std::max(max, static_cast<int>(size));
        }
        int result = 0;
        for(auto i : map) {
            if(i.second.size() == max) {
                ++result;
            }
        }
        return result;
    }
};
