// https://leetcode.com/problems/fizz-buzz/
// 
// Write a program that outputs the string representation of numbers from 1 to n.
// 
// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
// 
// Example:
// 
// n = 15,
// 
// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> result;
        for(int i = 1; i <= n; ++i) {
            auto t = std::to_string(i);
            if(i % 3 == 0) {
                t = "Fizz";
            }
            if(i % 5 == 0) {
                t = "Buzz";
            }
            if(i % 3 == 0 && i % 5 == 0) {
                t = "FizzBuzz";
            }
            result.push_back(t);
        }
        return result;
    }
};
