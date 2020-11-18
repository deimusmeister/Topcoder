// https://leetcode.com/problems/reformat-date/
// 
// Given a date string in the form Day Month Year, where:
// 
// Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
// Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
// Year is in the range [1900, 2100].
// Convert the date string to the format YYYY-MM-DD, where:
// 
// YYYY denotes the 4 digit year.
// MM denotes the 2 digit month.
// DD denotes the 2 digit day.
//  
// 
// Example 1:
// 
// Input: date = "20th Oct 2052"
// Output: "2052-10-20"
// Example 2:
// 
// Input: date = "6th Jun 1933"
// Output: "1933-06-06"
// Example 3:
// 
// Input: date = "26th May 1960"
// Output: "1960-05-26"
//  
// 
// Constraints:
// 
// The given dates are guaranteed to be valid, so no error handling is necessary.

class Solution {
public:
    string reformatDate(string date) {
        std::string day = "";
        std::string month = "";
        std::string year = "";
        
        std::string t = "";
        for(auto i : date) {
            if(day.empty()) {
                if(i == 'n' || i == 's' || i == 't' || i == 'h' || i == 'n' || i == 'd' || i == 'r') {
                    continue;
                } else if (i == ' '){
                    day = t;
                    t = "";
                } else {
                    t = t + i;
                }
            } else if(month.empty()) {
                if(i == ' ') {
                    month = t;
                    t = "";
                } else {
                    t = t + i;
                }
            } else if(year.empty()) {
                t = t + i;
            }
        }
        year = t;
        std::vector<std::string> list {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int count = 1;
        for(auto i : list) {
            if(i == month) {
                break;
            } else {
                ++count;
            }
        }
        month = std::to_string(count);
        month = count < 10 ? "0" + month : month;
        day = (day.length() == 1 ? "0" + day : day);
        
        return year + "-" + month + "-" + day;
    }
};
