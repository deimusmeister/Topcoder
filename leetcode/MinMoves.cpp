// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// 
// Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
// 
// Example:
// 
// Input:
// [1,2,3]
// 
// Output:
// 3
// 
// Explanation:
// Only three moves are needed (remember each move increments two elements):
// 
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int result = 0;
        long long sum = 0;
        long long n = nums.size();
        long long min = std::numeric_limits<int>::max();
        for(long long i : nums) {
            sum += i;
            min = std::min(min, i);
        }
        result = static_cast<int>(sum - n * min);
        return result;
    }
    // int minMoves(vector<int>& nums) {
    //     int result = 0;
    //     int n = nums.size();
    //     std::multiset<int> st;
    //     for(auto i : nums) {
    //         st.insert(i);
    //     }
    //     std::cout << "First: " << *(st.begin()) << std::endl;
    //     std::cout << "End: " << *(st.rbegin()) << std::endl;
    //     while(*(st.begin()) != *(st.rbegin())) {
    //         for(int i = 0; i < n - 1; ++i) {
    //             auto t = *st.begin();
    //             st.erase(st.begin());
    //             st.insert(t + 1);
    //         }
    //         ++result;
    //     }     
    //     return result;
    // }
};
