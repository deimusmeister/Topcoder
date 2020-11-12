// https://leetcode.com/problems/moving-stones-until-consecutive/
// 
// Three stones are on a number line at positions a, b, and c.
// 
// Each turn, you pick up a stone at an endpoint (ie., either the lowest or highest position stone), and move it to an unoccupied position between those endpoints.  Formally, let's say the stones are currently at positions x, y, z with x < y < z.  You pick up the stone at either position x or position z, and move that stone to an integer position k, with x < k < z and k != y.
// 
// The game ends when you cannot make any more moves, ie. the stones are in consecutive positions.
// 
// When the game ends, what is the minimum and maximum number of moves that you could have made?  Return the answer as an length 2 array: answer = [minimum_moves, maximum_moves]
// 
//  
// 
// Example 1:
// 
// Input: a = 1, b = 2, c = 5
// Output: [1,2]
// Explanation: Move the stone from 5 to 3, or move the stone from 5 to 4 to 3.
// Example 2:
// 
// Input: a = 4, b = 3, c = 2
// Output: [0,0]
// Explanation: We cannot make any moves.
// Example 3:
// 
// Input: a = 3, b = 5, c = 1
// Output: [1,2]
// Explanation: Move the stone from 1 to 4; or move the stone from 1 to 2 to 4.
//  
// 
// Note:
// 
// 1 <= a <= 100
// 1 <= b <= 100
// 1 <= c <= 100
// a != b, b != c, c != a

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        std::vector<int> line{a , b, c};
        std::sort(line.begin(), line.end());
        int delta1 = line[1] - line[0] - 1;
        int delta2 = line[2] - line[1] - 1;
        int max = delta1 + delta2;
        int min = 0;
        if(delta1 > 1 && delta2 > 1) {
            min = 2;
        } else if(delta1 > 0 || delta2 > 0) {
            min = 1;
        } else {
            min = 0;
        }
        std::vector<int> result;
        result.push_back(min);
        result.push_back(max);
        return result;
    }
};
