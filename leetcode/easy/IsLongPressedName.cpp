// https://leetcode.com/problems/long-pressed-name/
// 
// Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
// 
// You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
// 
//  
// 
// Example 1:
// 
// Input: name = "alex", typed = "aaleex"
// Output: true
// Explanation: 'a' and 'e' in 'alex' were long pressed.
// Example 2:
// 
// Input: name = "saeed", typed = "ssaaedd"
// Output: false
// Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
// Example 3:
// 
// Input: name = "leelee", typed = "lleeelee"
// Output: true
// Example 4:
// 
// Input: name = "laiden", typed = "laiden"
// Output: true
// Explanation: It's not necessary to long press any character.
//  
// 
// Constraints:
// 
// 1 <= name.length <= 1000
// 1 <= typed.length <= 1000
// The characters of name and typed are lowercase letters.

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.length() > typed.length()) {
            return false;
        }
        
        int n1 = name.length();
        int n2 = typed.length();
        if(n1 == 1 && n2 == 1) {
            return name == typed;
        }
        
        int count = 1;
        std::vector<std::pair<char, int>> mmp;
        for(int i = 1; i < n1; ++i) {
            if(name[i] == name[i - 1]) {
                ++count;
            } else {
                // std::cout << count << " times " << name[i - 1] << std::endl;
                auto p = std::make_pair(name[i - 1], count);
                mmp.push_back(p);
                count = 1;
            }
        }
        auto p = std::make_pair(name[n1 - 1], count);
        mmp.push_back(p);
        
        count = 1;
        std::vector<std::pair<char, int>> ttp;
        for(int i = 1; i < n2; ++i) {
            if(typed[i] == typed[i - 1]) {
                ++count;
            } else {
                auto p = std::make_pair(typed[i - 1], count);
                ttp.push_back(p);
                count = 1;
            }
        }
        p = std::make_pair(typed[n2 - 1], count);
        ttp.push_back(p);
        
        for(auto i : mmp) {
            std::cout << i.first << "->" << i.second << " "; 
        }
        std::cout << std::endl << std::endl;
        for(auto i : ttp) {
            std::cout << i.first << "->" << i.second << " "; 
        }
        std::cout << std::endl << std::endl;
        
        
        if(mmp.size() != ttp.size()) {
            return false;
        } else {
            int n = mmp.size();
            for(int i = 0; i < n; ++i) {
                auto nname = mmp[i];
                auto ttyped = ttp[i];
                if(nname.first != ttyped.first) {
                    return false;
                }
                if(nname.second > ttyped.second) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
