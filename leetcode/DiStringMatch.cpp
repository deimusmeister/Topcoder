// https://leetcode.com/problems/di-string-match/submissions/
// 
// Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
// 
// Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:
// 
// If S[i] == "I", then A[i] < A[i+1]
// If S[i] == "D", then A[i] > A[i+1]
//  
// 
// Example 1:
// 
// Input: "IDID"
// Output: [0,4,1,3,2]
// Example 2:
// 
// Input: "III"
// Output: [0,1,2,3]
// Example 3:
// 
// Input: "DDI"
// Output: [3,2,0,1]
//  
// 
// Note:
// 
// 1 <= S.length <= 10000
// S only contains characters "I" or "D".

class Solution {
public:
    vector<int> diStringMatch(string S) {
        std::vector<int> result;
        int max = S.length();
        int min = 0;
        for(auto i : S) {
            if(i == 'I') {
                result.push_back(min++);
            }
            if(i == 'D') {
                result.push_back(max--);
            }
        }
        if(S.back() == 'I') {
            result.push_back(min++);
        }
        if(S.back() == 'D') {
            result.push_back(max--);
        }
        return result;
    }
};
