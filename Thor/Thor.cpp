// Thor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/**
* Solve this puzzle by writing the shortest code.
* Whitespaces (spaces, new lines, tabs...) are counted in the total amount of chars.
* These comments should be burnt after reading!
**/
int main()
{
	int LX; // the X position of the light of power
	int LY; // the Y position of the light of power
	int TX; // Thor's starting X position
	int TY; // Thor's starting Y position
	cin >> LX >> LY >> TX >> TY; cin.ignore();
	string direction_x, direction_y, answer;
	int distance_x = TX - LX;
	int distance_y = TY - LY;
	int hX, hY;
	if (distance_x < 0) {
		direction_x = "E";
		hX = 1;
	}
	else
	{
		direction_x = "W";
		hX = -1;
	}
	if (distance_y < 0)
	{
		direction_y = "S";
		hY = 1;
	}
	else
	{
		direction_y = "N";
		hY = -1;
	}

	// game loop
	while (1) {
		int remainingTurns; // The level of Thor's remaining energy, representing the number of moves he can still make.
		if (distance_x != 0 && distance_y != 0) {
			cout << direction_y + direction_x << endl;
			distance_x += hX;
			distance_y += hY;
		}
		if (distance_x == 0)
		{
			cout << direction_y << endl;
			distance_y += hY;
		}
		if (distance_y == 0)
		{
			cout << direction_x << endl;
			distance_x += hX;
		}
		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;


		// A single line providing the move to be made: N NE E SE S SW W or NW
		//cout << "SE" << endl;
	}
}

