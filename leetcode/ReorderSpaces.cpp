// https://leetcode.com/problems/rearrange-spaces-between-words/
// 
// You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.
// 
// Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.
// 
// Return the string after rearranging the spaces.
// 
//  
// 
// Example 1:
// 
// Input: text = "  this   is  a sentence "
// Output: "this   is   a   sentence"
// Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
// Example 2:
// 
// Input: text = " practice   makes   perfect"
// Output: "practice   makes   perfect "
// Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
// Example 3:
// 
// Input: text = "hello   world"
// Output: "hello   world"
// Example 4:
// 
// Input: text = "  walks  udp package   into  bar a"
// Output: "walks  udp  package  into  bar  a "
// Example 5:
// 
// Input: text = "a"
// Output: "a"
//  
// 
// Constraints:
// 
// 1 <= text.length <= 100
// text consists of lowercase English letters and ' '.
// text contains at least one word.

class Solution {
public:
    string reorderSpaces(string t) {
        int n = t.size();
        int count = 0;
        int scount = 0;
        if(t[0] == ' ') {
            ++scount;
        }
        for(int i = 1; i < n; ++i) {
            if(t[i - 1] != ' ' && t[i] == ' ') {
                ++count;
            }
            if(t[i] == ' ') {
                ++scount;
            }
        }
        if(t[n - 1] != ' ') {
            ++count;
        }
        int dist = 0;
        int remn = 0;
        if(count != 1) {
            dist = scount / (count - 1);
            remn = scount % (count - 1);
            scount -= remn;
        } else {
            dist = scount;
        }
        std::string result;
        bool set = false;
        for(auto i : t) {
            if(i != ' ') {
                set = true;
                result += i;
            } else if(set && scount != 0) {
                set = false;
                int m = dist;
                while(m != 0) {
                    result += " ";
                    --m;
                }
                scount -= dist;
            }
        }
        if(set) {
            int m = scount;
            while(m != 0) {
                result += " ";
                --m;
            }
        }
        while(remn != 0) {
            result += " ";
            --remn;
        }
        return result;
    }
};
