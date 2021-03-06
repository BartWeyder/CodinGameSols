// MIMEType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	const string unknown = "UNKNOWN";
	int N; // Number of elements which make up the association table.
	cin >> N; cin.ignore();
	int Q; // Number Q of file names to be analyzed.
	cin >> Q; cin.ignore();
	unordered_map<string, string> table;
	vector<string>answer(Q);
	for (int i = 0; i < N; i++) {
		string EXT; // file extension
		string MT; // MIME type.
		cin >> EXT >> MT; cin.ignore();
		transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
		table.emplace(EXT, MT);
	}
	for (int i = 0; i < Q; i++) {
		string FNAME; // One file name per line.
		getline(cin, FNAME);
		transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::tolower);
		auto position = FNAME.find_last_of(".");
		if(position != FNAME.length() - 1 && position != string::npos)
			answer[i] = FNAME.substr(position + 1);
		else 
			answer[i] = unknown;
	}

	for (auto&  output : answer)
	{
		if (output != unknown)
		{
			unordered_map<string, string>::const_iterator position = table.find(output);
			if (position != table.end())
			{
				cout << position->second << endl;
			}
			else cout << unknown << endl;
		}
		else
			cout << output << endl;
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;


	// For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
}

