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

int V;
std::vector<int> adj[1000];
std::vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int installed;

int dfs(int here) {
	
	visited[here] = true;
	int children[3] = { 0,0,0 };
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there])
			++children[dfs(there)];
	}

	if (children[UNWATCHED]) {
		installed++;
		return INSTALLED;
	}

	if (children[INSTALLED])
		return WATCHED;
	return UNWATCHED;
}

int installCamera() {
	installed = 0;
	visited = std::vector<bool>(V, false);
	for (int u = 0; u < V; u++) {
		if (!visited[u] && dfs(u) == UNWATCHED) {
			++installed;
		}
	}
	return installed;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input28_8.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		int num;

		instream >> V >> num;


		int a, b;

		for (int j = 0; j < num; j++) {
			instream >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int ans = installCamera();

		std::cout << ans << std::endl;

		for (int j = 0; j < V; j++)
			adj[j].clear();
	}

	instream.close();

	system("pause");
}