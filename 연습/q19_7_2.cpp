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

int N, K;

int optimize(std::vector<int>& signal) {
	int ret = 0, tail = 0, rangeSum = signal[0];
	
	for (int head = 0; head < signal.size(); head++) {
		while (rangeSum < K && tail + 1 < signal.size())
			rangeSum += signal[++tail];

		if (rangeSum == K) ret++;

		rangeSum -= signal[head];
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
		instream >> K >> N;

		unsigned seed;

		seed = 1983;
	
		std::vector<int> signal;

		for (int i = 1; i <= N; i++) {
			signal.push_back(seed % 10000 + 1);
			seed = ((seed * 214013u) + 2531011u);
		}


		int ans = optimize(signal);

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}