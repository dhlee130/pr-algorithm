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

std::map<std::vector<int>, int> toSort;

void preCalc(int n) {
	std::vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;
	std::queue<std::vector<int> > q;

	q.push(perm);
	toSort[perm] = 0;

	while (!q.empty()) {
		std::vector<int> here = q.front();
		q.pop();
		int cost = toSort[here];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				std::reverse(here.begin() + i, here.begin() + j);
				if (toSort.count(here) == 0) {
					toSort[here] = cost + 1;
					q.push(here);
				}
				std::reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
}

int solve(const std::vector<int>& perm) {
	int n = perm.size();
	std::vector<int> fixed(n);

	for (int i = 0; i < n; i++) {
		int smaller = 0;
		for (int j = 0; j < n; j++)
			if (perm[j] < perm[i])
				smaller++;
		fixed[i] = smaller;
	}

	return toSort[fixed];
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input29_2.txt");
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

		std::vector<int> perm;

		int in;
		for (int i = 0; i < num; i++) {
			instream >> in;
			perm.push_back(in);
		}

		preCalc(num);
		int ans = solve(perm);

		std::cout << ans << std::endl;

		toSort.clear();
	}

	instream.close();

	system("pause");
}