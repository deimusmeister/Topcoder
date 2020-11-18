// https://leetcode.com/problems/goat-latin/
// 
// A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.
// 
// We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)
// 
// The rules of Goat Latin are as follows:
// 
// If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
// For example, the word 'apple' becomes 'applema'.
//  
// If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
// For example, the word "goat" becomes "oatgma".
//  
// Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
// For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
// Return the final sentence representing the conversion from S to Goat Latin. 
// 
//  
// 
// Example 1:
// 
// Input: "I speak Goat Latin"
// Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
// Example 2:
// 
// Input: "The quick brown fox jumped over the lazy dog"
// Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"



class Solution {
public:
    string toGoatLatin(string S) {
        std::string result = "";
        int count = 1;

        bool isWorldStart = true;
        bool isVowel = false;
        char consonant = '.';

        for(auto i : S) {
            if (isWorldStart) {
                isVowel = (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U');
                isWorldStart = false;
                if(!isVowel) {
                    consonant = i;
                } else {
                    result = result + i;
                }
            } else if (i == ' ') {
                if(!isVowel) {
                    result = result + consonant + "ma";
                } else {
                    result = result + "ma";
                }
                result += std::string(count, 'a');
                result += " ";

                isWorldStart = true;
                isVowel = false;
                ++count;
            } else {
                result = result + i;
            }
        }
        if(!isVowel) {
            result = result + consonant + "ma";
        } else {
            result = result + "ma";
        }
        result += std::string(count, 'a');

        isWorldStart = true;
        isVowel = false;
        ++count;
        return result;
    }
};
