// https://leetcode.com/problems/buddy-strings/
// 
// Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.
// 
// Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
// 
//  
// 
// Example 1:
// 
// Input: A = "ab", B = "ba"
// Output: true
// Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
// Example 2:
// 
// Input: A = "ab", B = "ab"
// Output: false
// Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
// Example 3:
// 
// Input: A = "aa", B = "aa"
// Output: true
// Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
// Example 4:
// 
// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
// Example 5:
// 
// Input: A = "", B = "aa"
// Output: false
//  
// 
// Constraints:
// 
// 0 <= A.length <= 20000
// 0 <= B.length <= 20000
// A and B consist of lowercase letters.


class Solution {
public:
    bool buddyStrings(string A, string B) {
        int n = A.length();
        int m = B.length();
        if(n != m) {
            return false;
        }
        if(A == B) {
            std::unordered_set<int> st;
            for(auto i : A) {
                if(st.find(i) != st.end()) {
                    return true;
                } else {
                    st.insert(i);
                }
            }
            return false;
        }
        std::unordered_map<char, int> mp;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(B[i] != A[i]) {
                mp[A[i]] = i;
                ++count;
            }
            if(count > 2) {
                return false;
            }
        }
        if(mp.size() != 2) {
            return false;
        }
        auto i = mp.begin();
        auto c1 = i->first;
        auto i1 = i->second;
        i = std::next(i);
        auto c2 = i->first;
        auto i2 = i->second;
       
        return B[i1] == c2 && B[i2] == c1;
    }
};
