// https://leetcode.com/problems/reverse-only-letters/
// 
// Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.
// 
// Example 1:
// 
// Input: "ab-cd"
// Output: "dc-ba"
// Example 2:
// 
// Input: "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:
// 
// Input: "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"
//  
// 
// Note:
// 
// S.length <= 100
// 33 <= S[i].ASCIIcode <= 122 
// S doesn't contain \ or "

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int start = 0;
        int end = S.length() - 1;
        while(start < end) {
            auto cstart = std::tolower(S[start]);
            while((cstart < 'a' || cstart > 'z') && start < end) {
                start++;
                cstart = std::tolower(S[start]);
            }
            auto cend = std::tolower(S[end]);
            while((cend < 'a' || cend > 'z') && start < end) {
                end--;
                cend = std::tolower(S[end]);
            }
            if(start < end) {
                std::swap(S[start++], S[end--]);
            }
        }
        return S;
    }
};
