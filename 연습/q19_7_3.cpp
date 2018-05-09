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
#include <random>

struct RNG {
	unsigned seed;

	RNG() : seed(1983) {}

	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};
int countRanges(int k, int n) {
	RNG rng;
	std::queue<int> range;
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		while (rangeSum > k) {
			rangeSum -= range.front();
			range.pop();
		}

		if (rangeSum == k) ret++;
	}
	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input19_7.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		int k, n;

		instream >> k >> n;

		


		int ans = countRanges(k, n);

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}