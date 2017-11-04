// SolveApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	string s;
	cin >> s; cin.ignore();
	bool isPolyndrome = true;
	int maxLength = 0;
	list<string> answers;

	for (int i = 0; i < s.length(); i++) 
	{
		for (int  j = s.length() - 1; j >i; j--)
		{
			if (j - i + 1 < maxLength)
				break;
			if ((j-i) % 2 == 1)
			{
				//then it's even count of letters in word
				for (int k = 0; k <= (j - i + 1) / 2; k++)
				{
					if (s[i+k] != s[j-k])
					{
						isPolyndrome = false;
						break;
					}
				}
			}
			else
			{
				int middleLetPos = (j - i) / 2;
				for (int k = 0; k < middleLetPos; k++)
				{
					if (s[i+k] != s[j-k])
					{
						isPolyndrome = false;
						break;
					}
				}
			}
			if (isPolyndrome && (j - i + 1 > maxLength))
			{
				answers.clear();
				answers.push_back(s.substr(i, j - i + 1));
				maxLength = j - i + 1;
			}
			else if (isPolyndrome && (j - i + 1 == maxLength))
				answers.push_back(s.substr(i, j - i + 1));
			isPolyndrome = true;
		}
	}
	for (string & answer : answers)
	{
		cout << answer + "\n";
	}
	cin.get();
    return 0;
}

