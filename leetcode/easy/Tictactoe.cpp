// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// 
// Tic-tac-toe is played by two players A and B on a 3 x 3 grid.
// 
// Here are the rules of Tic-Tac-Toe:
// 
// Players take turns placing characters into empty squares (" ").
// The first player A always places "X" characters, while the second player B always places "O" characters.
// "X" and "O" characters are always placed into empty squares, never on filled ones.
// The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
// The game also ends if all squares are non-empty.
// No more moves can be played if the game is over.
// Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play.
// 
// Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".
// 
// You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.
// 
//  
// 
// Example 1:
// 
// Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
// Output: "A"
// Explanation: "A" wins, he always plays first.
// "X  "    "X  "    "X  "    "X  "    "X  "
// "   " -> "   " -> " X " -> " X " -> " X "
// "   "    "O  "    "O  "    "OO "    "OOX"
// Example 2:
// 
// Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
// Output: "B"
// Explanation: "B" wins.
// "X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
// "   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
// "   "    "   "    "   "    "   "    "   "    "O  "
// Example 3:
// 
// Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
// Output: "Draw"
// Explanation: The game ends in a draw since there are no moves to make.
// "XXO"
// "OOX"
// "XOX"
// Example 4:
// 
// Input: moves = [[0,0],[1,1]]
// Output: "Pending"
// Explanation: The game has not finished yet.
// "X  "
// " O "
// "   "
//  
// 
// Constraints:
// 
// 1 <= moves.length <= 9
// moves[i].length == 2
// 0 <= moves[i][j] <= 2
// There are no repeated elements on moves.
// moves follow the rules of tic tac toe.

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        std::vector<std::vector<int>> mp;
        for(int i = 0; i < 3; ++i) {
            std::vector<int> row;
            for(int j = 0; j < 3; ++j) {
                row.push_back(0);
            }
            mp.push_back(row);
        }
        bool isA = true;
        for(auto i : moves) {
            auto x = i[0];
            auto y = i[1];
            if(isA) {
                mp[x][y] = 1;
            } else {
                mp[x][y] = -1;
            }
            isA = !isA;
        }
        std::string result = "";
        for(int i = 0; i < 3; ++i) {
            auto row = checkRow(mp, i);
            auto col = checkCol(mp, i);
            if(!row.empty()) {
                result = row;
                break;
            }
            if(!col.empty()) {
                result = col;
                break;
            }
        }
        if(result.empty()) {
            result = checkDiag(mp);
        } 
        if(result.empty()) {
            result = checkRevDiag(mp);
        } 
        if(result.empty() && moves.size() == 9) {
            result = "Draw";
        } 
        if(result.empty()) {
            result = "Pending";
        }
        return result;
    }
    std::string checkRow(const std::vector<std::vector<int>>& mp, int row) {
        if(mp[row][0] != 0 && mp[row][0] == mp[row][1] && mp[row][0] == mp[row][2]) {
            if(mp[row][0] == 1) {
                return "A";
            } else {
                return "B";
            }
        }
        return "";
    }
    std::string checkCol(const std::vector<std::vector<int>>& mp, int col) {
        if(mp[0][col] != 0 && mp[0][col] == mp[1][col] && mp[0][col] == mp[2][col]) {
            if(mp[0][col] == 1) {
                return "A";
            } else {
                return "B";
            }
        }
        return "";
    }
    std::string checkDiag(const std::vector<std::vector<int>>& mp) {
        if(mp[0][0] != 0 && mp[0][0] == mp[1][1] && mp[0][0] == mp[2][2]) {
            if(mp[0][0] == 1) {
                return "A";
            } else {
                return "B";
            }
        }
        return "";
    }
    std::string checkRevDiag(const std::vector<std::vector<int>>& mp) {
        if(mp[2][0] != 0 && mp[2][0] == mp[1][1] && mp[2][0] == mp[0][2]) {
            if(mp[2][0] == 1) {
                return "A";
            } else {
                return "B";
            }
        }
        return "";
    }
};
