// https://leetcode.com/problems/shortest-distance-to-a-character/
// 
// Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
// 
// Example 1:
// 
// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
//  
// 
// Note:
// 
// S string length is in [1, 10000].
// C is a single character, and guaranteed to be in string S.
// All letters in S and C are lowercase.


class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        std::vector<int> result;
        bool first = true;
        int count = 0;
        for(auto i : S) {
            if(i == C) {
                std::cout << count << std::endl;
                if(first) {
                    for(int i = count; i >= 0; --i) {
                        result.push_back(i);
                    }
                    first = false;
                } else {
                    auto n = count / 2;
                    if(count % 2 == 1) {
                        ++n;
                    }
                    for(int i = 1; i <= n; ++i) {
                        result.push_back(i);
                    }
                    for(int i = count / 2; i >= 0; --i) {
                        result.push_back(i);
                    }
                }
                count = 0;
            } else {
                ++count;
            }
        }
        if(count != 0) {
            for(int i = 1; i <= count; ++i) {
                result.push_back(i);
            }
        }
        return result;
    }
};
