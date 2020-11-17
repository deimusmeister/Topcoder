// https://leetcode.com/problems/excel-sheet-column-title/
// 
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// 
// For example:
// 
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
//     ...
// Example 1:
// 
// Input: 1
// Output: "A"
// Example 2:
// 
// Input: 28
// Output: "AB"
// Example 3:
// 
// Input: 701
// Output: "ZY"

class Solution {
public:
    string convertToTitle(int n) {
        std::string result = "";
        if(n == 1) {
            return "A";
        }
        n = n - 1;
        bool first = true;
        while(n != 0) {
            int r = n % 26;
            if(!first) {
                r -= 1;
                if(r < 0) {
                    r = 25;
                    n /= 26;
                }
            }
            char c = 'A' + r;
            result = c + result;
            n = n / 26;
            first = false;
        }
        return result;
    }
};
