// https://leetcode.com/problems/relative-ranks/
// 
// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
// 
// Example 1:
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
// For the left two athletes, you just need to output their relative ranks according to their scores.
// Note:
// N is a positive integer and won't exceed 10,000.
// All the scores of athletes are guaranteed to be unique.

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        std::vector<std::string> result;
        std::map<int, int, std::greater<int>> mp;
        
        for(auto i : nums) {
            mp[i] = 0;
        }
        int count = 0;
        for(auto& i : mp) {
            std::cout << i.first << " ";
            i.second = ++count;
        }
        for(auto i : nums) {
            int pos = mp[i];
            if(1 == pos) {
                result.push_back("Gold Medal");
            } else if(2 == pos) {
                result.push_back("Silver Medal");
            } else if(3 == pos) {
                result.push_back("Bronze Medal");
            } else {
                result.push_back(std::to_string(pos));
            }
        }
        return result;
    }
};
