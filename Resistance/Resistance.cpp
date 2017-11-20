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
vector<string>dictionary;
static size_t word_min_size = 99999999;
static size_t possible_counter = 0;
static size_t message_length;
static size_t max_combination_level = 0;
static string message;

void try_combine(string expression, size_t level);
bool check_word(string word);
size_t get_word_weight(string word);

int main()
{
	vector<char>weights{ 2, 4, 4, 3, 1, 4, 3, 4, 2, 4, 3, 4, 2, 2, 3, 4, 4, 3, 3, 1, 3, 4, 3, 4, 4, 4 };
	for (size_t i = 0; i < weights.size(); i++)
		weights_table.emplace(char(i + 65), weights[i]);
	string L;
	cin >> L; cin.ignore();
	message = L;
	message_length = L.length();
	int N;
	cin >> N; cin.ignore();
	vector<string>single(N);
	for (int i = 0; i < N; i++) {
		string W;
		cin >> W; cin.ignore();
		single[i] = W;
		auto temp_size = get_word_weight(W);
		if (temp_size < word_min_size)
			word_min_size =	temp_size;
	}
	dictionary = single;
	max_combination_level = message_length / word_min_size;
	for (auto& word : dictionary)
	{
		try_combine(word, 0);
	}

	cout << possible_counter << endl;
	cin.get();
}


void try_combine(string expression, size_t level)
{
	check_word(expression);
	if (level < max_combination_level && get_word_weight(expression) <= message_length)
	{
		for (auto &word : dictionary)
		{
			try_combine(expression + word, level + 1);
		}
	}
}

bool check_word(string word)
{
	if (message_length <= word.length() * 4) {
		
		
		if (get_word_weight(word) == message_length)
		{
			size_t current_position = 0;
			for (size_t i = 0; i < word.length(); i++)
			{
				auto code_part = code_table[word[i]];
				if (message.find(code_part, current_position) != current_position)
				{
					return false;
				}
				current_position += code_part.length();
			}
			possible_counter++;
			return true;
		}
	}
	return false;
}

size_t get_word_weight(string word)
{
	size_t summ = 0;
	for (size_t i = 0; i < word.length(); i++)
		summ += weights_table[word[i]];
	return summ;
}
