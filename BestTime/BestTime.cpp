// BestTime.cpp : Defines the entry point for the console application.
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
	string answer;
	int N;
	cin >> N; cin.ignore();
	for (int i = 0; i < N; i++) {
		string t;
		cin >> t; cin.ignore();
		if (i == 0)
			answer = t;
		else {
			size_t answer_h = stoi(answer.substr(0, 2));
			size_t answer_m = stoi(answer.substr(3, 2));
			size_t answer_s = stoi(answer.substr(6, 2));
			size_t t_h = stoi(t.substr(0, 2));
			size_t t_m = stoi(t.substr(3, 2));
			size_t t_s = stoi(t.substr(6, 2));
			if (t_h < answer_h)
				answer = t;
			else if (t_h == answer_h) {
				if (t_m < answer_m)
					answer = t;
				else if (t_m == answer_m) {
					if (t_s < answer_s)
						answer = t;
				}
			}
		}
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << answer << endl;
}

