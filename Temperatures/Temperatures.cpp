// Temperatures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int n; // the number of temperatures to analyse
	cin >> n; cin.ignore();
	int answer;
	for (int i = 0; i < n; i++) {
		int t; // a temperature expressed as an integer ranging from -273 to 5526
		cin >> t; cin.ignore();

		if (i == 0)
			answer = t;
		else if (abs(answer) > abs(t))
			answer = t;
		else if (abs(answer) == abs(t) && t > 0)
			answer = t;
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << answer << endl;
}
