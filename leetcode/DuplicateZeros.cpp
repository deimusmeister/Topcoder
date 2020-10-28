// https://leetcode.com/problems/duplicate-zeros/
// 
// Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.
// 
// Note that elements beyond the length of the original array are not written.
// 
// Do the above modifications to the input array in place, do not return anything from your function.
// 
//  
// 
// Example 1:
// 
// Input: [1,0,2,3,0,4,5,0]
// Output: null
// Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
// Example 2:
// 
// Input: [1,2,3]
// Output: null
// Explanation: After calling your function, the input array is modified to: [1,2,3]
//  
// 
// Note:
// 
// 1 <= arr.length <= 10000
// 0 <= arr[i] <= 9

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0;
        for(auto i : arr) {
            if(i == 0) {
                ++count;
            }
        }
        int n = arr.size();
        for(int i = n - 1; i >= 0; --i) {
            auto id = i + count;
            if(arr[i] == 0) {
                if(id < n) {
                    arr[id] = arr[i];
                }
                --count;
            }
            id = i + count;
            if(id < n) {
                arr[id] = arr[i];
            }
        }
    }
    // void duplicateZeros(vector<int>& arr) {
    //     std::vector<int> result;
    //     int count = 0;
    //     for(auto i : arr) {
    //         if(count == arr.size()) {
    //             break;
    //         }
    //         ++count;
    //         result.push_back(i);
    //         if(count == arr.size()) {
    //             break;
    //         }
    //         if(i == 0) {
    //             ++count;
    //             result.push_back(i);
    //         }
    //     }
    //     std::copy(result.begin(), result.end(), arr.begin());
    // }
};
