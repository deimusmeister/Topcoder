// https://leetcode.com/problems/find-common-characters/
// 
// Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.
// 
// You may return the answer in any order.
// 
//  
// 
// Example 1:
// 
// Input: ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:
// 
// Input: ["cool","lock","cook"]
// Output: ["c","o"]
//  
// 
// Note:
// 
// 1 <= A.length <= 100
// 1 <= A[i].length <= 100
// A[i][j] is a lowercase letter

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        std::unordered_map<char, int> map;
        for(auto i : A[0]) {
            if(map.find(i) == map.end()) {
                map[i] = 1;
            } else {
                ++map[i];
            }
        }
        for(auto i : A) {
            std::unordered_map<char, int> localMap;
            for(auto j : i) {
                if(localMap.find(j) == localMap.end()) {
                    localMap[j] = 1;
                } else {
                    ++localMap[j];
                }   
            }
            for(auto i = map.begin(); i != map.end();) {
                if(localMap.find(i->first) == localMap.end()) {
                    i = map.erase(i);
                } else {
                    i->second = std::min(i->second, localMap[i->first]);
                    ++i;
                }
            }
        }
        std::vector<std::string> result;
        for(auto i : map) {
            for(auto j = 0; j < i.second; ++j) {
                result.emplace_back(1, i.first);   
            }
        }
        return result;
    }
};
