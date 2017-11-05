// Vortex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Coord
{
	int i, j, value;
	Coord(int i, int j, int value)
	{
		this->i = i;
		this->j = j;
		this->value = value;
	}
};

void MoveRight(vector< vector<int> > matrix, vector< vector<int> > &answer, int moves, Coord el);
void MoveDown(vector< vector<int> > matrix, vector< vector<int> > &answer, int moves, Coord el);
void MoveLeft(vector< vector<int> > matrix, vector< vector<int> > &answer, int moves, Coord el);
void MoveUp(vector< vector<int> > matrix, vector< vector<int> > &answer, int moves, Coord el);

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int W;
	int H;
	cin >> W >> H; cin.ignore();
	int X;
	cin >> X; cin.ignore();
	int fullCycle;
	int mvs = X;
	vector< vector<int> > matrix(H, vector<int>(W));
	vector< vector<int> > answer(H, vector<int>(W));

	int Wmin, Hmin, coreW, coreH;
	int borderCount = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int v;
			cin >> v; cin.ignore();
			matrix[i][j] = v;
		}
	}
	if (W % 2 == 0)
	{
		if (W <= H)
			Wmin = 0;
		else
			Wmin = 2;
	}
	else
		Wmin = 1;

	if (H % 2 == 0)
	{
		if (H <= W)
			Hmin = 0;
		else
			Hmin = 2;
	}
	else
		Hmin = 1;

	coreH = H - Hmin;
	coreW = W - Wmin;

	while (coreH != 0 && coreW != 0)
	{
		coreH -= 2;
		coreW -= 2;
		borderCount++;
	}
	//finally this is dimesion of core that is not rotating
	coreH += Hmin;
	coreW += Wmin;
	
	for (int i = borderCount; i < borderCount + coreH; i++)
	{
		for (int j = borderCount; j < borderCount + coreW; j++)
		{
			answer[i][j] = matrix[i][j];
		}
	}
	
	for (int i = 0; i < borderCount; i++)
	{
		mvs = X;
		fullCycle = (W - i * 2 - 1) * 2 + (H - i * 2 - 1) * 2;
		if (mvs >= fullCycle)
			mvs = mvs - (mvs / fullCycle) * fullCycle;
		
		for (int j = i; j < H - i - 1; j++)
		{
			MoveDown(matrix, answer, mvs, Coord(j, i, matrix[j][i]));
		}
		for (int j = i; j < W - i - 1; j++)
		{
			MoveRight(matrix, answer, mvs, Coord(H - 1 - i, j, matrix[H - 1 - i][j]));
		}
		for (int j = H - i - 1; j > i; j--)
		{
			MoveUp(matrix, answer, mvs, Coord(j, W - i - 1, matrix[j][W - i - 1]));
		}
		for (int j = W - i - 1; j > i; j--)
		{
			MoveLeft(matrix, answer, mvs, Coord(i, j, matrix[i][j]));
		}
		
	}
	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << answer[i][j];
			if (j == W - 1)
				cout << endl;
			else
				cout << " ";
		}
	}
	cin.get();
	//cout << "Matrix" << endl;
}

void MoveRight(vector<vector<int>> matrix, vector<vector<int>>& answer, int moves, Coord el)
{
	int borderCount = matrix.size() - el.i - 1;
	if (matrix[0].size() - el.j - borderCount - 1 >= moves)
		answer[el.i][el.j + moves] = el.value;
	else
	{
		moves -= matrix[0].size() - el.j - borderCount - 1;
		MoveUp(matrix, answer, moves, Coord(el.i, matrix[0].size() - borderCount - 1, el.value));
	}
}

void MoveDown(vector<vector<int>> matrix, vector<vector<int>>& answer, int moves, Coord el)
{
	int borderCount = el.j;
	if (matrix.size() - el.i - borderCount - 1 >= moves)
		answer[el.i + moves][el.j] = el.value;
	else
	{
		moves -= matrix.size() - el.i - borderCount - 1;
		MoveRight(matrix, answer, moves, Coord(matrix.size() - 1 - borderCount, el.j, el.value));
	}
}

void MoveLeft(vector<vector<int>> matrix, vector<vector<int>>& answer, int moves, Coord el)
{
	int borderCount = el.i;
	if (el.j - borderCount >= moves)
		answer[el.i][el.j - moves] = el.value;
	else
	{
		moves -= el.j - borderCount;
		MoveDown(matrix, answer, moves, Coord(el.i, borderCount, el.value));
	}
}

void MoveUp(vector<vector<int>> matrix, vector<vector<int>>& answer, int moves, Coord el)
{
	int borderCount = matrix[0].size() - el.j - 1;
	if (el.i - borderCount >= moves)
		answer[el.i - moves][el.j] = el.value;
	else
	{
		moves -= el.i - borderCount;
		MoveLeft(matrix, answer, moves, Coord(borderCount, el.j, el.value));
	}
}
