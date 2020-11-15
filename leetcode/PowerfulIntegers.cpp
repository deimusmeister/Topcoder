// https://leetcode.com/problems/powerful-integers/
// 
// Given two positive integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.
// 
// Return a list of all powerful integers that have value less than or equal to bound.
// 
// You may return the answer in any order.  In your answer, each value should occur at most once.
// 
//  
// 
// Example 1:
// 
// Input: x = 2, y = 3, bound = 10
// Output: [2,3,4,5,7,9,10]
// Explanation: 
// 2 = 2^0 + 3^0
// 3 = 2^1 + 3^0
// 4 = 2^0 + 3^1
// 5 = 2^1 + 3^1
// 7 = 2^2 + 3^1
// 9 = 2^3 + 3^0
// 10 = 2^0 + 3^2
// Example 2:
// 
// Input: x = 3, y = 5, bound = 15
// Output: [2,4,6,8,10,14]
//  
// 
// Note:
// 
// 1 <= x <= 100
// 1 <= y <= 100
// 0 <= bound <= 10^6

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        std::vector<int> result;
        std::unordered_set<int> mp;
        int max1 = 0;
        if(x != 1) {
            max1 = log(bound) / log(x) + 1;
        }
        int max2 = 0;
        if(y != 1) {
            max2 = log(bound) / log(y) + 1;
        }
        
        for(int i = 0; i <= max1; ++i) {
            for(int j = 0; j <= max2; ++j) {
                auto val = std::pow(x, i) + std::pow(y, j);
                if(val <= bound && mp.find(val) == mp.end()) {
                    mp.insert(val);
                    result.push_back(val);
                }
            }
        }
        return result;
    }
};  
