#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct Tile
{
	int x, y;
	Tile(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

bool find_path(vector< vector<int> > &field, int currentX, int currentY);
bool is_connected(vector< vector<int> > field, int currentX, int currentY);
/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int W;
	int H;
	cin >> W >> H; cin.ignore();
	bool path_found = false;
	int answer = 0;
	vector< vector<int> > field(W, vector<int>(H));
	field[0][0] = 1;
	field[W - 1][H - 1] = 1;
	for (int i = 0; i < 158; i++) {
		int tileX;
		int tileY;
		cin >> tileX >> tileY; cin.ignore();
		field[tileX][tileY] = 1;
		if (!path_found)
		{
			if (i == 0 && find_path(field, 0, 0))
			{
				answer = 1;
				path_found = true;
				break;
			}
			if (is_connected(field, tileX, tileY) && find_path(field, tileX, tileY))
			{
				answer = i + 1;
				path_found = true;
				break;
			}
		}
		

	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << answer << endl;
	cin.get();
}

bool find_path(vector< vector<int> > &field, int currentX, int currentY)
{
	if (currentX == field.size() - 1 && currentY == field[0].size() - 1)
	{
		return true;
	}
	else
	{
		field[currentX][currentY] = -1;
	}
	list<Tile> ways;
	ways.clear();
	if (currentX > 0 && field[currentX-1][currentY] == 1)
	{
		ways.push_back(Tile(currentX - 1, currentY));
	}
	if (currentX < field.size() - 1 && field[currentX + 1][currentY] == 1)
	{
		ways.push_back(Tile(currentX + 1, currentY));
	}
	if (currentY > 0 && field[currentX][currentY -1] == 1)
	{
		ways.push_back(Tile(currentX, currentY - 1));
	}
	if (currentY < field[0].size() - 1 && field[currentX][currentY + 1] == 1)
	{
		ways.push_back(Tile(currentX, currentY + 1));
	}
	if (ways.size() == 0)
	{
		return false;
	}
	else
	{
		for (Tile & way : ways)
		{
			if (find_path(field, way.x, way.y))
				return true;
		}
	}
	return false;
}

bool is_connected(vector<vector<int>> field, int currentX, int currentY)
{
	if (
		(currentX > 0 && field[currentX - 1][currentY] == -1) ||
		(currentX < field.size() - 1 && field[currentX + 1][currentY] == -1) ||
		(currentY > 0 && field[currentX][currentY - 1] == -1) ||
		(currentY < field[0].size() - 1 && field[currentX][currentY + 1] == -1)
		)
		return true;
	else
		return false;
}
