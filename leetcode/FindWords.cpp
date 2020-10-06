// https://leetcode.com/problems/keyboard-row/
// 
// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
//  
// Example:
// 
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
//  
// 
// Note:
// 
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        std::string row1 = "qwertyuiop";
        std::string row2 = "asdfghjkl";
        std::string row3 = "zxcvbnm";
        std::unordered_map<char, int> keyboard;
        for(auto i : row1) {
            keyboard[i] = 1;
        }
        for(auto i : row2) {
            keyboard[i] = 2;
        }
        for(auto i : row3) {
            keyboard[i] = 3;
        }
        std::vector<std::string> result;
        for(auto word : words) {
            auto let = word[0];
            let = std::tolower(let);
            auto line = keyboard[let];
            bool sameline = true;
            for(auto i : word) {
                auto t = std::tolower(i);
                if(line != keyboard[t]) {
                    sameline = false;
                    break;
                }            
            }
            if(sameline) {
                result.push_back(word);
            }
        }
        return result;
    }
};
