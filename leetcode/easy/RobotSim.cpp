// https://leetcode.com/problems/walking-robot-simulation/
// 
// A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:
// 
// -2: turn left 90 degrees
// -1: turn right 90 degrees
// 1 <= x <= 9: move forward x units
// Some of the grid squares are obstacles. 
// 
// The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])
// 
// If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)
// 
// Return the square of the maximum Euclidean distance that the robot will be from the origin.
// 
//  
// 
// Example 1:
// 
// Input: commands = [4,-1,3], obstacles = []
// Output: 25
// Explanation: robot will go to (3, 4)
// Example 2:
// 
// Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
// Output: 65
// Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
//  
// 
// Note:
// 
// 0 <= commands.length <= 10000
// 0 <= obstacles.length <= 10000
// -30000 <= obstacle[i][0] <= 30000
// -30000 <= obstacle[i][1] <= 30000
// The answer is guaranteed to be less than 2 ^ 31.

class Solution {
public:
    enum Position {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int max = 0;
        std::unordered_set<std::string> st;
        for(auto i : obstacles) {
            std::string t = std::to_string(i[0]) + ":" + std::to_string(i[1]);
            st.insert(t);
        }
        
        Position pos = NORTH;
        int x = 0;
        int y = 0;
        
        for(auto i : commands) {
            switch(i) {
                case -1: {
                    if(pos == NORTH) {
                        pos = EAST;
                    } else if(pos == EAST) {
                        pos = SOUTH;
                    } else if(pos == SOUTH) {
                        pos = WEST;
                    } else if(pos == WEST) {
                        pos = NORTH;
                    }
                } break;
                case -2: {
                    if(pos == NORTH) {
                        pos = WEST;
                    } else if(pos == WEST) {
                        pos = SOUTH;
                    } else if(pos == SOUTH) {
                        pos = EAST;
                    } else if(pos == EAST) {
                        pos = NORTH;
                    }
                } break;
                default: {
                    for(int j = 0; j < i; ++j) {
                        bool met = false;
                        switch(pos) {
                            case NORTH: {
                                std::string t = std::to_string(x) + ":" + std::to_string(y + 1);
                                if(st.find(t) != st.end()) {
                                    met = true;
                                } else {
                                    y += 1;   
                                }
                            } break;
                            case EAST: {
                                std::string t = std::to_string(x + 1) + ":" + std::to_string(y);
                                if(st.find(t) != st.end()) {
                                    met = true;
                                } else {
                                    x += 1;   
                                }
                            } break;
                            case SOUTH: {
                                std::string t = std::to_string(x) + ":" + std::to_string(y - 1);
                                if(st.find(t) != st.end()) {
                                    met = true;
                                } else {
                                    y -= 1;   
                                }
                            } break;
                            case WEST: {
                                std::string t = std::to_string(x - 1) + ":" + std::to_string(y);
                                if(st.find(t) != st.end()) {
                                    met = true;
                                } else {
                                    x -= 1;   
                                }
                            } break;
                        }
                        if(met) {
                            break;
                        }
                    }
                    max = std::max(max, x * x + y * y);
                }    
            }
        }
        
        return max;
    }
};
