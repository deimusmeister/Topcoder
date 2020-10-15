// https://leetcode.com/problems/maximum-number-of-balloons/
// 
// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
// 
// You can use each character in text at most once. Return the maximum number of instances that can be formed.
// 
// Example 1:
// 
// Input: text = "nlaebolko"
// Output: 1
// Example 2:
// 
// Input: text = "loonbalxballpoon"
// Output: 2
// Example 3:
// 
// Input: text = "leetcode"
// Output: 0
//  
// Constraints:
// 
// 1 <= text.length <= 10^4
// text consists of lower case English letters only.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        std::unordered_map<char, int> mp;
        for(auto i : text) {
            if(mp.find(i) == mp.end()) {
                mp[i] = 1;
            } else {
                mp[i]++;
            }
        }
        // balloon
        for(auto i : "balloon") {
            if(mp.find(i) == mp.end()) {
                mp[i] = 0;
            }
        }
        int min = std::numeric_limits<int>::max();
        for(auto i : mp) {
            switch(i.first) {
                case 'b': { min = std::min(min, i.second); } break;
                case 'a': { min = std::min(min, i.second); } break;
                case 'l': { min = std::min(min, i.second / 2); } break;
                case 'o': { min = std::min(min, i.second / 2); } break;
                case 'n': { min = std::min(min, i.second); } break;
            }
        }
        return min;
    }
};
