// https://leetcode.com/problems/uncommon-words-from-two-sentences/
// 
// We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)
// 
// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
// 
// Return a list of all uncommon words. 
// 
// You may return the list in any order.
// 
//  
// 
// Example 1:
// 
// Input: A = "this apple is sweet", B = "this apple is sour"
// Output: ["sweet","sour"]
// Example 2:
// 
// Input: A = "apple apple", B = "banana"
// Output: ["banana"]
//  
// 
// Note:
// 
// 0 <= A.length <= 200
// 0 <= B.length <= 200
// A and B both contain only spaces and lowercase letters.


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        std::unordered_map<std::string, int> map;
        std::string word{};
        for(auto i : A) {
            if(i == ' ') {
                if(map.find(word) == map.end()) {
                    map[word] = 1;
                } else {
                    map[word]++;
                }
                word = "";
            } else {
                word = word + i;
            }
        }
        if(!word.empty()) {
            if(map.find(word) == map.end()) {
                map[word] = 1;
            } else {
                map[word]++;
            }
        }
        word = "";
        for(auto i : B) {
            if(i == ' ') {
                if(map.find(word) == map.end()) {
                    map[word] = 1;
                } else {
                    map[word]++;
                }
                word = "";
            } else {
                word = word + i;
            }
        }
        if(!word.empty()) {
            if(map.find(word) == map.end()) {
                map[word] = 1;
            } else {
                map[word]++;
            }
        }
        std::vector<std::string> result;
        for(auto i : map) {
            if(i.second == 1) {
                result.push_back(i.first);
            }
        }
        return result;
    }
};
