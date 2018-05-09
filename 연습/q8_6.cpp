#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>

int INF = 987654321;

std::string N;

int classify(int a, int b) {
	std::string M = N.substr(a, b - a + 1);

	if (M == std::string(M.size(), M[0])) return 1;

	bool progressive = true;

	for (int i = 1; i < M.size(); i++)
		if (M[i] - M[i - 1] != M[1] - M[0])
			progressive = false;

	if (progressive && abs(M[1] - M[0]) == 1) return 2;

	bool alternative = true;

	for (int i = 0; i < M.size(); i++)
		if (M[i] != M[i % 2])
			alternative = false;

	if (progressive) return 5;
	if (alternative) return 4;

	return 10;
}

int cache[10001];

int memorize(int begin) {
	if (begin == N.size()) return 0;

	int &ret = cache[begin];
	if (ret != -1) return ret;

	ret = INF;
	for (int L = 3; L <= 5; L++) {
		if (begin + L <= N.size())
			ret = std::min(ret, memorize(begin + L) + classify(begin, begin + L-1));
	}

	return ret;
}


void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input8_6.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		instream >> N;

		memset(cache, -1, sizeof(cache));

		int ans = memorize(0);

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}