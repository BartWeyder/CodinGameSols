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
unordered_map<string, string>word_code_table;
static size_t word_min_size = 99999999;
static size_t possible_counter = 0;
static size_t message_length;
static size_t max_combination_level = 0;
static string message;

void try_combine(string expression, string code, size_t level);
int check_word(string word);
size_t get_word_weight(string word);
string get_code(string word);

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
	for (int i = 0; i < N; i++) {
		string W;
		cin >> W; cin.ignore();
		word_code_table.emplace(W, get_code(W));
		auto temp_size = word_code_table[W].length();
		if (temp_size < word_min_size)
			word_min_size =	temp_size;
	}
	max_combination_level = message_length / word_min_size;
	for (auto& word : word_code_table)
	{
		try_combine(word.first, word_code_table[word.first], 0);
	}

	cout << possible_counter << endl;
	cin.get();
}



void try_combine(string expression, string code, size_t level) {
	switch (check_word(code))
	{
	case 1:
	case -1:
		return;
		break;
	case 0:
		if (level < max_combination_level && code.length() + word_min_size <= message_length)
		{
			for (auto &word : word_code_table)
			{
				try_combine(expression + word.first, code + word_code_table[word.first], level + 1);
			}
		}
		break;
	default:
		break;
	}		
}

int check_word(string word_code)
{
	if (word_code.length() == message_length)
	{
		if (word_code == message)
		{
			possible_counter++;
			return 1;
		}
	}
	else if (word_code.length() < message_length)
	{
		if (message.find(word_code) == 0)
		{
			return 0;
		}
		else
			return -1;
	}
	else 
		return -1;
}

size_t get_word_weight(string word)
{
	size_t summ = 0;
	for (size_t i = 0; i < word.length(); i++)
		summ += weights_table[word[i]];
	return summ;
}

string get_code(string word)
{
	string result = "";
	for (size_t i = 0; i < word.length(); i++)
	{
		result += code_table[word[i]];
	}
	return result;
}
