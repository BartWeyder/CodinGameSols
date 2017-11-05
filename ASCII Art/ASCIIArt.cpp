// ASCIIArt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
	string lowerCase = "abcdefghijklmnopqrstuvwxyz?";
	int L;
	cin >> L; cin.ignore();
	int H;
	cin >> H; cin.ignore();
	//27 letters: 1 letter = H strings
	vector< vector<string> > letters(27, vector<string>(H));
	string T;
	getline(cin, T);
	list<int> indexes;
	for (int i = 0; i < T.length(); i++)
	{
		int upperPos = distance(upperCase.begin(), find(upperCase.begin(), upperCase.end(), T[i]));
		int lowerPos = distance(lowerCase.begin(), find(lowerCase.begin(), lowerCase.end(), T[i]));
		if (upperPos >= upperCase.size())
		{
			if (lowerPos >= lowerCase.size())
				indexes.push_back(26);
			else
				indexes.push_back(lowerPos);
		}
		else
			indexes.push_back(upperPos);
	}
	for (int i = 0; i < H; i++) {
		string ROW;
		getline(cin, ROW);
		for (int j = 0; j < letters.size(); j++)
			letters[j][i] = ROW.substr(j * L, L);
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;
	for (int i = 0; i < H; i++)
	{
		for (int & index : indexes)
			cout << letters[index][i];
		cout << endl;
	}
}

