// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// 
// You are given an array of strings words and a string chars.
// 
// A string is good if it can be formed by characters from chars (each character can only be used once).
// 
// Return the sum of lengths of all good strings in words.
// 
//  
// 
// Example 1:
// 
// Input: words = ["cat","bt","hat","tree"], chars = "atach"
// Output: 6
// Explanation: 
// The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
// Example 2:
// 
// Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
// Output: 10
// Explanation: 
// The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
//  
// 
// Note:
// 
// 1 <= words.length <= 1000
// 1 <= words[i].length, chars.length <= 100
// All strings contain lowercase English letters only.

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        std::unordered_map<char, int> map;
        for(auto i : chars) {
            if(map.find(i) == map.end()) {
                map[i] = 1;
            } else {
                ++map[i];
            }
        }
        int sum = 0;
        for(auto i : words) {
            std::unordered_map<char, int> localMap(map.begin(), map.end());
            bool ok = true;
            for(auto j : i) {
                if(localMap.find(j) == localMap.end()) {
                    ok = false;
                    break;
                } else if(localMap[j] > 0) {
                    --localMap[j];
                } else {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                sum += i.length();
            }
        }
        return sum;
    }
};
