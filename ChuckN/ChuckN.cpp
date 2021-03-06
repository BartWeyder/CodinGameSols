// ChuckN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	string MESSAGE;
	getline(cin, MESSAGE);
	size_t bitCounter = 0;
	string binaryString = "";
	for (int i = 0; i < MESSAGE.length(); i++)
	{
		binaryString += bitset<7>(MESSAGE.c_str()[i]).to_string();
	}
	char bit = binaryString[0];
	bitCounter++;
	for (int j = 1; j < binaryString.length(); j++)
	{
		if (bit == binaryString[j])
			bitCounter++;
		else
		{
			if (bit == '0')
				cout << "00 ";
			else
				cout << "0 ";
			for (int k = 0; k < bitCounter; k++)
				cout << "0";
			cout << " ";
			bit = binaryString[j];
			bitCounter = 1;
		}
	}
	if (bit == '0')
		cout << "00 ";
	else
		cout << "0 ";
	for (int k = 0; k < bitCounter; k++)
		cout << "0";
	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << endl;
}

