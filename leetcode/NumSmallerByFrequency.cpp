// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// 
// Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.
// 
// Now, given string arrays queries and words, return an integer array answer, where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.
// 
//  
// 
// Example 1:
// 
// Input: queries = ["cbd"], words = ["zaaaz"]
// Output: [1]
// Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
// Example 2:
// 
// Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
// Output: [1,2]
// Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
//  
// 
// Constraints:
// 
// 1 <= queries.length <= 2000
// 1 <= words.length <= 2000
// 1 <= queries[i].length, words[i].length <= 10
// queries[i][j], words[i][j] are English lowercase letters.


class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        std::vector<int> result;
        std::vector<int> etalon;
        for(auto i : words) {
            etalon.push_back(f(i));
        }
        std::sort(etalon.begin(), etalon.end(), std::greater<>());
        for(auto i : queries) {
            auto t = f(i);
            int count = 0;
            for(auto j : etalon) {
                if(j > t) {
                    ++count;
                } else {
                    break;
                }
            }
            result.push_back(count);
        }
        return result;
    }
    int f(const std::string& s) {
        std::map<char, int> mp;
        for(auto i : s) {
            if(mp.find(i) == mp.end()) {
                mp[i] = 1;
            } else {
                mp[i]++;
            }
        }
        auto fe = mp.begin();
        return fe->second;
    }
};
