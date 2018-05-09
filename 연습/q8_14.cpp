#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>

int cache[101][101];
const int MOD = 10 * 1000 * 1000;

int poly(int num, int first) {
	if (num == first) return 1;

	int& ret = cache[num][first];
	if (ret != -1) return ret;

	ret = 0;
	for (int second = 1; second <= num - first; second++) {
		int add = second + first - 1;
		add *= poly(num - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}

	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input8_14.txt");
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

		memset(cache, -1, sizeof(cache));

		int ans = 0;

		for (int j = 1; j <= num; j++) {
			ans += poly(num, j);
			ans %= MOD;
		}

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}