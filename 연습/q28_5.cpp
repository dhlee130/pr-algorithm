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
std::vector<std::string> graph[26][26];
std::vector<int> indegree, outdegree;

void makeGraph(const std::vector<std::string>& words) {
	adj = std::vector<std::vector<int>>(26, std::vector<int>(26, 0));

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			graph[i][j].clear();

	indegree = outdegree = std::vector<int>(26, 0);

	for (int i = 0; i < words.size(); i++) {
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		indegree[b]++;
		outdegree[a]++;
	}
}

void getEulerCircuit(int here, std::vector<int>& circuit) {
	for (int there = 0; there < adj.size(); there++) {
		while (adj[here][there] > 0) {
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}

std::vector<int> getEulerTrailOrCircuit() {
	std::vector<int> circuit;

	for(int i=0; i<26; i++)
		if (indegree[i] + 1 == outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}

	for(int i=0; i<26;i++)
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	return circuit;
}

bool checkEuler() {
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];

		if (delta < -1 || delta > 1) return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;
	}

	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

std::string solve(const std::vector<std::string>& words) {
	makeGraph(words);

	if (!checkEuler()) return "IMPOSSIBLE";

	std::vector<int> circuit = getEulerTrailOrCircuit();

	if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";

	std::reverse(circuit.begin(), circuit.end());
	std::string ret;
	for (int i = 1; i < circuit.size(); i++) {
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input28_5.txt");
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

		std::string ans = solve(words);

		std::cout << ans << std::endl;

	}

	instream.close();

	system("pause");
}