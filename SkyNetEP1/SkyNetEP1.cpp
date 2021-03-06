// SkyNetEP1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

list<int> find_best_route(vector< vector<int> > nodes, int current, int destination, vector<int>& used_nodes);
list<int> get_unchecked_nodes(int n, vector<int> used_nodes);
/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int N; // the total number of nodes in the level, including the gateways
	int L; // the number of links
	int E; // the number of exit gateways
	cin >> N >> L >> E; cin.ignore();
	vector< vector<int> > nodes(N, vector<int>(N));
	vector<int> gateways(E);
	for (int i = 0; i < L; i++) {
		int N1; // N1 and N2 defines a link between these nodes
		int N2;
		cin >> N1 >> N2; cin.ignore();
		nodes[N1][N2] = 1;
		nodes[N2][N1] = 1;
	}
	for (int i = 0; i < E; i++) {
		int EI; // the index of a gateway node
		cin >> EI; cin.ignore();
		gateways[i] = EI;
	}

	// game loop
	while (1) {
		int SI; // The index of the node on which the Skynet agent is positioned this turn
		cin >> SI; cin.ignore();
		list<int> best_route;
		for (auto& gateway : gateways) {
			vector<int> used_nodes(1, SI);
			list<int> possible_route( find_best_route(nodes, SI, gateway, used_nodes) );
			if (best_route.size() > possible_route.size() || best_route.empty())
				best_route = possible_route;

		}
		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;


		// Example: 0 1 are the indices of the nodes you wish to sever the link between
		cout << SI << " ";
		cout << *best_route.begin() << endl;
		/*for (iterator; iterator != best_route.end(); ++iterator);
		{
			cout << " " << *iterator;
		}
		cout << endl;*/
	}
}

list<int> find_best_route(vector< vector<int> > nodes, int current, int destination, vector<int>& used_nodes)
{
	if (nodes[current][destination] == 1)
		return { destination };
	list<int> best_route;
	list<int> unchecked_nodes (get_unchecked_nodes(nodes.size(), used_nodes));
	for (auto& node : unchecked_nodes)
	{
		if (nodes[current][node] == 1)
		{
			used_nodes.push_back(node);
			list<int> possible_route{ node };
			list<int> new_route = find_best_route(nodes, node, destination, used_nodes);
			if (new_route.size() != 0)
			{
				possible_route.insert(possible_route.end(), new_route.begin(), new_route.end());
				if (best_route.size() < possible_route.size())
					best_route = possible_route;
			}
		}
	}
	if (best_route.size() <= 1)
		return list<int> {};
	else
		return best_route;
}

list<int> get_unchecked_nodes(int n, vector<int> used_nodes) {
	list<int> unchecked_nodes;
	for (int i = 0; i < n; i++)
	{
		if (find(used_nodes.begin(), used_nodes.end(), i) == used_nodes.end())
			unchecked_nodes.push_back(i);
	}
	return unchecked_nodes;
}
