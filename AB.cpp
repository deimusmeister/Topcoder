/*
 Problem Statement
 
 You are given two s : N and K.Lun the dog is interested in strings that satisfy the following conditions :
 
 The string has exactly N characters, each of which is either 'A' or 'B'.
 The string s has exactly K pairs(i, j) (0 <= i < j <= N - 1) such that s[i] = 'A' and s[j] = 'B'.
 
 If there exists a string that satisfies the conditions, find and return any such string.Otherwise, return an empty string.
 Definition
 Class :
 AB
 Method :
 createString
 Parameters :
 int, int
 Returns :
 string
 Method signature :
 string createString(int N, int K)
 (be sure your method is public)
 Limits
 Time limit(s) :
 2.000
 Memory limit(MB) :
 256
 Constraints
 - N will be between 2 and 50, inclusive.
 - K will be between 0 and N(N - 1) / 2, inclusive.
 Examples
 0)
 3
 2
 Returns: "ABB"
 This string has exactly two pairs(i, j) mentioned in the statement : (0, 1) and(0, 2).
 
 1)
 2
 0
 Returns: "BA"
 Please note that there are valid test cases with K = 0.
 
 2)
 5
 8
 Returns: ""
 Five characters is too short for this value of K.
 
 3)
 10
 12
 Returns: "BAABBABAAB"
 Please note that this is an example of a solution; other valid solutions will also be accepted.
*/

#include <iostream>

#include <string>

struct AB
{
	std::string createString(int N, int K)
	{
		std::string strB(N - N / 2, 'B');
		std::string strA(N / 2, 'A');
		std::string str = strB + strA;
		if(K > N * N / 4)
		{
			return "";
		}
		if(K == 0)
		{
			return str;
		}
		int count = 0;
		for(size_t i = 0; i < N - 1; ++i)
		{
			for(size_t j = 0; j < N - 1; ++j)
			{
				if(str[j] == 'B' && str[j + 1] == 'A')
				{
					std::swap(str[j], str[j + 1]);
					count++;
					if(count == K)
					{
						return str;
					}
				}
			}
		}
		return "";
	}
};

int main()
{
	AB obj;
	std::string result = obj.createString(10, 12);
	std::cout << "result : " << result << std::endl;

	std::string n;
	std::cin >> n;
	return 0;
}

