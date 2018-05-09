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
#include <assert.h>

const int MAX_N = 10001;
int n, m[MAX_N], e[MAX_N];

int lunchtime() {
	std::vector<std::pair<int, int> > order;

	for (int i = 0; i < n; i++)
		order.push_back(std::make_pair(-e[i], i));

	int ret = 0, eatStart = 0;
	for (int i = 0; i < n; i++) {
		int box = order[i].second;
		eatStart += m[box];
		ret = std::max(ret, eatStart + e[box]);
	}

	return ret;
}


void main()
{
	
	std::ifstream instream;
	int numtestcases;

	instream.open("input10_2.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	

	for (int i = 0; i < numtestcases; i++)
	{
		instream >> n;

		for (int j = 0; j < n; j++)
			instream >> m[j];
		for (int j = 0; j < n; j++)
			instream >> e[j];
		
		int ans = lunchtime();

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}