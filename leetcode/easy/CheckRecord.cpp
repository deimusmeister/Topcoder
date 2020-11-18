// https://leetcode.com/problems/student-attendance-record-i/
// 
// You are given a string representing an attendance record for a student. The record only contains the following three characters:
// 'A' : Absent.
// 'L' : Late.
// 'P' : Present.
// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
// 
// You need to return whether the student could be rewarded according to his attendance record.
// 
// Example 1:
// Input: "PPALLP"
// Output: True
// Example 2:
// Input: "PPALLL"
// Output: False

class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        int countL = 0;
        for(const auto& i : s) {
            if(i == 'L') {
                ++countL;
            } else {
                if(i == 'A') {
                    ++countA;
                }
                countL = 0;
            }
            if(countA > 1 || countL > 2) {
                return false;
            }
        }
        if(countA > 1 || countL > 2) {
            return false;
        }
        return true;
    }
};
