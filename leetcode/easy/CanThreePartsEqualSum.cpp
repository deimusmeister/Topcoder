// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// 
// Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.
// 
// Formally, we can partition the array if we can find indexes i+1 < j with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])
// 
//  
// 
// Example 1:
// 
// Input: A = [0,2,1,-6,6,-7,9,1,2,0,1]
// Output: true
// Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
// Example 2:
// 
// Input: A = [0,2,1,-6,6,7,9,-1,2,0,1]
// Output: false
// Example 3:
// 
// Input: A = [3,3,6,5,-2,2,5,1,-9,4]
// Output: true
// Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
//  
// 
// Constraints:
// 
// 3 <= A.length <= 50000
// -10^4 <= A[i] <= 10^4

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        bool result = false;
        int n = A.size();
        std::unordered_map<int, std::vector<int>> mp1;
        std::unordered_map<int, std::vector<int>> mp2;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < n; ++i) {
            sum1 += A[i];
            sum2 += A[n - 1 - i];
            mp1[sum1].push_back(i);
            mp2[sum2].push_back(n - 1 - i);
        }
        for(auto& i : mp1) {
            auto first = i.first;
            auto third = sum1 - 2 * first;
            if(first != third) {
                continue;
            }
            if(mp2.find(third) != mp2.end()) {
                for(auto& ki : i.second) {
                    for(auto& kj : mp2[third]) {
                        if(kj - ki > 1) {
                            return true;
                        }
                    }
                }
            }
        }
        return result;
    }
};
