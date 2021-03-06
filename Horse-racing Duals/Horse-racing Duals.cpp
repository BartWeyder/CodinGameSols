// Horse-racing Duals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int N;
	cin >> N; cin.ignore();
	vector<int>powers(N);
	for (int i = 0; i < N; i++) {
		int Pi;
		cin >> Pi; cin.ignore();
		powers[i] = Pi;
	}
	sort(powers.begin(), powers.end());
	auto min_difference = abs(powers[1] - powers[0]);
	if (min_difference != 0)
		for (int i = 1; i < N - 1; i++)
		{
			if (abs(powers[i + 1] - powers[i]) < min_difference)
				min_difference = abs(powers[i + 1] - powers[i]);
		}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << min_difference << endl;
}

