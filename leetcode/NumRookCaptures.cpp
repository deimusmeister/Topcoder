// https://leetcode.com/problems/available-captures-for-rook/
// 
// On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.
// 
// The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.
// 
// Return the number of pawns the rook can capture in one move.
// 
//  
// 
// Example 1:
// 
// 
// 
// Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
// Output: 3
// Explanation: 
// In this example the rook is able to capture all the pawns.
// Example 2:
// 
// 
// 
// Input: [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
// Output: 0
// Explanation: 
// Bishops are blocking the rook to capture any pawn.
// Example 3:
// 
// 
// 
// Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
// Output: 3
// Explanation: 
// The rook can capture the pawns at positions b5, d6 and f5.
//  
// 
// Note:
// 
// board.length == board[i].length == 8
// board[i][j] is either 'R', '.', 'B', or 'p'
// There is exactly one cell with board[i][j] == 'R'


class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        int n = board.size();
        int rookx = -1;
        int rooky = -1;
        for(size_t i = 0; i < n; ++i) {
            for(size_t j = 0; j < n; ++j) {
                if(board[i][j] == 'R') {
                    rookx = i;
                    rooky = j;
                    break;
                }
            }
            if(rookx != -1) {
                break;
            }
        }
        // up
        for(int i = rookx; i >= 0; --i) {
            auto x = i;
            auto y = rooky;
            if(board[x][y] == 'R') {
                continue;
            }
            if(board[x][y] == '.') {
                continue;
            }
            if(board[x][y] == 'B') {
                break;
            }
            if(board[x][y] == 'p') {
                ++count;
                break;
            }
        }
        // down
        for(int i = rookx; i < n; ++i) {
            auto x = i;
            auto y = rooky;
            if(board[x][y] == 'R') {
                continue;
            }
            if(board[x][y] == '.') {
                continue;
            }
            if(board[x][y] == 'B') {
                break;
            }
            if(board[x][y] == 'p') {
                ++count;
                break;
            }
        }
        // right
        for(int i = rooky; i < n; ++i) {
            auto x = rookx;
            auto y = i;
            if(board[x][y] == 'R') {
                continue;
            }
            if(board[x][y] == '.') {
                continue;
            }
            if(board[x][y] == 'B') {
                break;
            }
            if(board[x][y] == 'p') {
                ++count;
                break;
            }
        }
        // left
        for(int i = rooky; i >= 0; --i) {
            auto x = rookx;
            auto y = i;
            if(board[x][y] == 'R') {
                continue;
            }
            if(board[x][y] == '.') {
                continue;
            }
            if(board[x][y] == 'B') {
                break;
            }
            if(board[x][y] == 'p') {
                ++count;
                break;
            }
        }
        return count;
    }
};
