// https://leetcode.com/problems/reorder-data-in-log-files/
// 
// You have an array of logs.  Each log is a space delimited string of words.
// 
// For each log, the first word in each log is an alphanumeric identifier.  Then, either:
// 
// Each word after the identifier will consist only of lowercase letters, or;
// Each word after the identifier will consist only of digits.
// We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.
// 
// Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.
// 
// Return the final order of the logs.
// 
//  
// 
// Example 1:
// 
// Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
// Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
//  
// 
// Constraints:
// 
// 0 <= logs.length <= 100
// 3 <= logs[i].length <= 100
// logs[i] is guaranteed to have an identifier, and a word after the identifier.

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::vector<std::string> result;
        std::vector<std::string> dresult;
        std::map<std::string, std::set<std::string>> lresult;
        for(int j = 0; j < logs.size(); ++j) {
            auto i = logs[j];
            bool found = false;
            bool isDigit = true;
            int count = 0;
            for(auto k : i) {
                if(k == ' ') {
                    found = true;
                    continue;
                }
                if(found) {
                    if (k >= 'a' && k <= 'z') {
                        isDigit = false;
                        auto key = i.substr(count);
                        lresult[key].insert(i);
                        break;
                    } else {
                        break;
                    }
                }
                ++count;
            }
            if(isDigit) {
                dresult.push_back(i);
            }
        }
        for(auto i : lresult) {
            for(auto j : i.second) {
                result.push_back(j);   
            }
        }
        std::copy(dresult.begin(), dresult.end(), std::back_inserter(result));
        return result;
    }
};
