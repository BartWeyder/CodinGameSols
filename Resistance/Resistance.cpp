// Resistance.cpp : Defines the entry point for the console application.
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
static unordered_map<char, int> weights_table;
static unordered_map<char, string> code_table({
	{ 'A', ".-" },
	{ 'B', "-..." },
	{ 'C', "-.-." },
	{ 'D', "-.." },
	{ 'E', "." },
	{ 'F', "..-." },
	{ 'G', "--." },
	{ 'H', "...." },
	{ 'I', ".." },
	{ 'J', ".---" },
	{ 'K', "-.-" },
	{ 'L', ".-.." },
	{ 'M', "--" },
	{ 'N', "-." },
	{ 'O', "---" },
	{ 'P', ".--." },
	{ 'Q', "--.-" },
	{ 'R', ".-." },
	{ 'S', "..." },
	{ 'T', "-" },
	{ 'U', "..-" },
	{ 'V', "...-" },
	{ 'W', ".--" },
	{ 'X', "-..-" },
	{ 'Y', "-.--" },
	{ 'Z', "--.." },
});
static vector< vector<string> > combinations;
static size_t word_min_size = 99999999;
static size_t possible_counter = 0;

int is_lenghts_equal(string word, size_t message_length);
bool is_possible(size_t rang, string message);


int main()
{
	vector<char>weights{ 2, 4, 4, 3, 1, 4, 3, 4, 2, 4, 3, 4, 2, 2, 3, 4, 4, 3, 3, 1, 3, 4, 3, 4, 4, 4 };
	for (size_t i = 0; i < weights.size(); i++)
		weights_table.emplace(char(i + 65), weights[i]);
	size_t possible_count = 0;
	string L;
	cin >> L; cin.ignore();
	const size_t message_length = L.length();
	int N;
	cin >> N; cin.ignore();
	vector<string>single(N);
	for (int i = 0; i < N; i++) {
		string W;
		cin >> W; cin.ignore();
		single[i] = W;
		auto temp_size = W.length();
		if (temp_size < word_min_size)
			word_min_size =	temp_size;
		//checking the length
		/*if (is_lenghts_equal(W, message_length))
		{
			if(is_possible(W, L))
				possible_count++;
		}*/
	}

	for (size_t i = 0; i < message_length / (word_min_size * 2) + 1; i++)
	{
		
	}

	// Write an action using cout. DON"T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << possible_count << endl;
}

int is_lenghts_equal(string word, size_t message_length)
{
	size_t summ = 0;
	for (size_t i = 0; i < word.length(); i++)
		summ += weights_table[word[i]];
	if (summ == message_length)
		return 0;
	return summ < message_length ?  -1 : 1;
}

/*bool is_possible(string word, string message)
{
	size_t current_position = 0;
	for (size_t i = 0; i < word.length(); i++)
	{
		auto code_part = code_table[word[i]];
		if (message.find(code_part, current_position) != current_position)
			return false;
		current_position += code_part.length();
	}
	return true;
}*/

