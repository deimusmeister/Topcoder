// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// 
// In a deck of cards, each card has an integer written on it.
// 
// Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:
// 
// Each group has exactly X cards.
// All the cards in each group have the same integer.
//  
// 
// Example 1:
// 
// Input: deck = [1,2,3,4,4,3,2,1]
// Output: true
// Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
// Example 2:
// 
// Input: deck = [1,1,1,2,2,2,3,3]
// Output: false´
// Explanation: No possible partition.
// Example 3:
// 
// Input: deck = [1]
// Output: false
// Explanation: No possible partition.
// Example 4:
// 
// Input: deck = [1,1]
// Output: true
// Explanation: Possible partition [1,1].
// Example 5:
// 
// Input: deck = [1,1,2,2,2,2]
// Output: true
// Explanation: Possible partition [1,1],[2,2],[2,2].
//  
// 
// Constraints:
// 
// 1 <= deck.length <= 10^4
// 0 <= deck[i] < 10^4

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        if(n == 1) {
            return false;
        }
        std::unordered_map<int, int> mp;
        for(auto i : deck) {
            mp[i]++;
        }
        int min = std::numeric_limits<int>::max();
        for(auto i : mp) {
            min = std::min(min, i.second);
        }
        if(min < 2) {
            return false;
        }
        std::vector<int> factors;
        for(int i = 2; i * i <= min; ++i) {
            if(min % i == 0) {
                factors.push_back(min / i);
                factors.push_back(i);
            }
        }
        factors.push_back(min);
        
        bool found = true;
        for(int j : factors) {
            found = true;
            for(auto i : mp) {
                if(i.second % j != 0) {
                    found = false;
                    break;
                }
            }
            if(found) {
                break;
            }
        }
        return found;
    }
};
