// https://leetcode.com/problems/occurrences-after-bigram/
// 
// Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.
// 
// For each such occurrence, add "third" to the answer, and return the answer.
// 
//  
// 
// Example 1:
// 
// Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
// Output: ["girl","student"]
// Example 2:
// 
// Input: text = "we will we will rock you", first = "we", second = "will"
// Output: ["we","rock"]
//  
// 
// Note:
// 
// 1 <= text.length <= 1000
// text consists of space separated words, where each word consists of lowercase English letters.
// 1 <= first.length, second.length <= 10
// first and second consist of lowercase English letters.


class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        std::vector<string> result;
        std::list<std::string> list;
        
        std::string word;
        for(auto i : text) {
            if(i == ' ') {
                if(!word.empty()) {
                    list.push_back(word);                    
                }
                word = "";
            } else {
                word = word + i;
            }
        }
        if(!word.empty()) {
            list.push_back(word);
        }
        for(auto i = list.begin(); i != list.end(); ++i) {
            if(*i == first) {
                auto next = std::next(i);
                if (next != list.end() && *next == second) {
                    auto third = std::next(next);
                    if (third != list.end()) {
                        result.push_back(*third);
                    }
                }
            }
        }
        return result;
    }
};
