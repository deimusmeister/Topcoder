// https://leetcode.com/problems/thousand-separator/
// 
// Given an integer n, add a dot (".") as the thousands separator and return it in string format.
// 
// Example 1:
// 
// Input: n = 987
// Output: "987"
// Example 2:
// 
// Input: n = 1234
// Output: "1.234"
// Example 3:
// 
// Input: n = 123456789
// Output: "123.456.789"
// Example 4:
// 
// Input: n = 0
// Output: "0"
//  
// 
// Constraints:
// 
// 0 <= n < 2^31

class Solution {
public:
    string thousandSeparator(int n) {
        if(n == 0) {
            return "0";
        }
        std::stack<int, std::vector<int>> st;
        while(n != 0) {
            st.push(n % 10);
            n = n / 10;
        }
        int count = 0;
        std::string result;
        while(!st.empty()) {
            auto t = st.top();
            st.pop();
            result = result + std::to_string(t);
            if(st.size() % 3 == 0 && !st.empty()) {
                result += ".";
            }
        }
        return result;
    }
};
