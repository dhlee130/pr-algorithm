#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <map>
#include <functional>

std::vector<std::vector<int>> adj;

void makeGraph(const std::vector<std::string>& words) {
	

	adj = std::vector<std::vector<int>>(26, std::vector<int>(26, 0));

	for (int j = 1; j < words.size(); j++) {
		int i = j - 1, len = std::min(words[i].size(), words[j].size());

		for (int k = 0; k < len; k++) {

			if (words[j][k] != words[i][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}

std::vector<int> seen, order;

void dfs(int here) {
	seen[here] = 1;

	for (int there = 0; there < adj.size(); there++) {
		if (adj[here][there] && !seen[there])
			dfs(there);
	}
	order.push_back(here);
}

std::vector<int> topologicalSort() {
	int n = adj.size();
	seen = std::vector<int>(n, 0);
	order.clear();
	for (int i = 0; i < n; i++) if (!seen[i]) dfs(i);
	std::reverse(order.begin(), order.end());
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (adj[order[j]][order[i]])
				return std::vector<int>();
	return order;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input28_2.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		int num;

		instream >> num;

		std::string input;
		std::vector<std::string> words;

		for (int j = 0; j < num; j++) {
			instream >> input;
			words.push_back(input);
		}

		adj.clear();
		makeGraph(words);
		std::vector<int> ans = topologicalSort();

		if (ans.size() == 0)
			std::cout << "INVALID HYPOTHESIS" << std::endl;
		else {
			for (int i = 0; i < ans.size(); i++)
				std::cout << (char)(ans[i] + 'a');
		}
		std::cout << std::endl;
	}

	instream.close();

	system("pause");
}