// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// 
// In a list of songs, the i-th song has a duration of time[i] seconds. 
// 
// Return the number of pairs of songs for which their total duration in seconds is divisible by 60.  Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.
// 
//  
// 
// Example 1:
// 
// Input: [30,20,150,100,40]
// Output: 3
// Explanation: Three pairs have a total duration divisible by 60:
// (time[0] = 30, time[2] = 150): total duration 180
// (time[1] = 20, time[3] = 100): total duration 120
// (time[1] = 20, time[4] = 40): total duration 60
// Example 2:
// 
// Input: [60,60,60]
// Output: 3
// Explanation: All three pairs have a total duration of 120, which is divisible by 60.
//  
// 
// Note:
// 
// 1 <= time.length <= 60000
// 1 <= time[i] <= 500

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        std::unordered_map<int, int> st;
        for(auto& i : time) {
            i = i % 60;
            st[i]++;
        }
        int count = 0;
        int n = time.size();
        for(int i = n - 1; i >= 0; --i) {
            auto t = time[i];
            if(st[t] > 0) {
                st[t]--;
                int p = (60 - t) % 60;
                if(st[p] > 0) {
                    count += st[p];
                }
            }
        }
        return count;
    }
};
