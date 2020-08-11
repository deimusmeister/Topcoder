/*
    Problem Statement

    One day, Jamie noticed that many English words only use the letters A and B. Examples of such words include "AB" (short for abdominal), "BAA" (the noise a sheep makes), "AA" (a type of lava), and "ABBA" (a Swedish pop sensation).

    Inspired by this observation, Jamie created a simple game. You are given two s: initial and target. The goal of the game is to find a sequence of valid moves that will change initial into target. There are two types of valid moves:

    Add the letter A to the end of the string.
    Reverse the string and then add the letter B to the end of the string.

    Return "Possible" (quotes for clarity) if there is a sequence of valid moves that will change initial into target. Otherwise, return "Impossible".
    Definition
    Class:
    ABBA
    Method:
    canObtain
    Parameters:
    string, string
    Returns:
    string
    Method signature:
    string canObtain(string initial, string target)
    (be sure your method is public)
    Limits
    Time limit (s):
    2.000
    Memory limit (MB):
    256
    Constraints
    - The length of initial will be between 1 and 999, inclusive.
    - The length of target will be between 2 and 1000, inclusive.
    - target will be longer than initial.
    - Each character in initial and each character in target will be either 'A' or 'B'.
    Examples
    0)
    "B"
    "ABBA"
    Returns: "Possible"
    Jamie can perform the following moves:

    Initially, the string is "B".
    Jamie adds an 'A' to the end of the string. Now the string is "BA".
    Jamie reverses the string and then adds a 'B' to the end of the string. Now the string is "ABB".
    Jamie adds an 'A' to the end of the string. Now the string is "ABBA".

    Since there is a sequence of moves which starts with "B" and creates the string "ABBA", the answer is "Possible".
    1)
    "AB"
    "ABB"
    Returns: "Impossible"
    The only strings of length 3 Jamie can create are "ABA" and "BAB".
    2)
    "BBAB"
    "ABABABABB"
    Returns: "Impossible"
    3)
    "BBBBABABBBBBBA"
    "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA"
    Returns: "Possible"
    4)
    "A"
    "BB"
    Returns: "Impossible"
*/

#include <iostream>

#include <string>
#include <algorithm>

struct ABBA
{
    std::string canObtain(std::string initial, std::string target)
    {
        if (initial.length() > target.length())
            return "Impossible";
        
        std::string reversedInitial = initial;
        
        std::reverse(reversedInitial.begin(), reversedInitial.end());
        
        int mode = 0; // 0 -- normal , 1 --- reverse
        
        while (!target.empty())
        {
            if (mode == 0 && target == initial)
                return "Possible";
            if (mode == 1 && target == reversedInitial)
                return "Possible";
            
            if (mode == 0)
            {
                if (*target.rbegin() == 'A')
                {
                    target.erase(target.length() - 1, 1);
                }
                else if (*target.rbegin() == 'B')
                {
                    target.erase(target.length() - 1, 1);
                    mode = 1;
                }
                else
                    break;
            }
            else if (mode == 1)
            {
                if (*target.begin() == 'A')
                {
                    target.erase(0, 1);
                }
                else if (*target.begin() == 'B')
                {
                    target.erase(0, 1);
                    mode = 0;
                }
                else
                    break;
            }
        }
        
        if (target == initial)
            return "Possible";

        return "Impossible";
    }
};

#include <iostream>

int main(int argc, const char * argv[])
{
    ABBA obj;
    

    std::cout << "result: " << obj.canObtain("BBBBABABBBBBBA", "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA") << std::endl;
    
    std::cout << "result: " << obj.canObtain("BBAB", "ABABABABB") << std::endl;
    
    std::cout << "result: " << obj.canObtain("AB", "ABB") << std::endl;

    std::cout << "result: " << obj.canObtain("A", "BB") << std::endl;
    
    std::cout << "result: " << obj.canObtain("B", "ABBA") << std::endl;
    
    return 0;
}
