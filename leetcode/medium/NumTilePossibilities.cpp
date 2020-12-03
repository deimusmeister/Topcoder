// https://leetcode.com/problems/letter-tile-possibilities/
// 
// You have n  tiles, where each tile has one letter tiles[i] printed on it.
// 
// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
// 
//  
// 
// Example 1:
// 
// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
// Example 2:
// 
// Input: tiles = "AAABBC"
// Output: 188
// Example 3:
// 
// Input: tiles = "V"
// Output: 1
//  
// 
// Constraints:
// 
// 1 <= tiles.length <= 7
// tiles consists of uppercase English letters.

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        for(int k = 1; k <= n; ++k) {
            std::string s;
            visit(tiles, s, n, k);
        }
        return st.size();
    }
    void visit(const std::string& t, const std::string s, int n, int k) {
        if(k == n + 1) {
            st.insert(s);
            return;
        }
        for(auto j = 0; j < n; ++j) {
            if(t[j] >= 'A' && t[j] <= 'Z') {
                std::string a{t};
                a[j] = '0';
                visit(a, s + t[j], n, k + 1);   
            }
        }
    }
private:
    std::unordered_set<std::string> st;
};
