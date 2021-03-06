// Defibrillators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits>
#include <cstddef>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
double get_distance(string input, double latitudeA, double longitudeA);
double get_coord(string coord);

int main()
{
	string answer;
	string LON;
	cin >> LON; cin.ignore();
	string LAT;
	cin >> LAT; cin.ignore();
	double original_lon = get_coord(LON);
	double original_lat = get_coord(LAT);
	int N;
	cin >> N; cin.ignore();
	double max_distance = std::numeric_limits<double>::max();
	for (int i = 0; i < N; i++) {
		string DEFIB;
		getline(cin, DEFIB);
		auto position = DEFIB.find_last_of(';');
		DEFIB[position] = '!';
		position = DEFIB.find_last_of(';');
		double new_distance = get_distance(DEFIB.substr(position + 1), original_lat, original_lon);
		if (new_distance < max_distance)
		{
			max_distance = new_distance;
			auto temp_pos = DEFIB.find(';');
			DEFIB.erase(0, temp_pos + 1);
			temp_pos = DEFIB.find(';');
			answer = DEFIB.substr(0, temp_pos);
		}
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << answer << endl;
}

double get_distance(string input, double latitudeA, double longitudeA)
{
	auto position = input.find('!');
	double longitudeB = get_coord(input.substr(0, position - 1));
	double latitudeB = get_coord(input.substr(position + 1, input.length() - position - 1));

	double x = (longitudeB - longitudeA) * cos((latitudeA + latitudeB) / 2);
	double y = (latitudeB - latitudeA);
	return sqrt(x*x + y*y) * 6371;
}

double get_coord(string coord)
{
	coord[coord.find(',')] = '.';
	return stod(coord);
}
