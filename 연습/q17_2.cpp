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

int N, K;

const int MOD = 20091101;

std::vector<int> box;

std::vector<int> psum;

std::vector<int> calcPsum(std::vector<int> box) {
	std::vector<int> ret(box.size());

	ret[0] = box[0];

	for (int i = 1; i < box.size(); i++) {
		ret[i] = ret[i - 1] + box[i];
	}

	return ret;
}

int rangeSum(int a, int b) {
	if (a == 0) return psum[b];
	return psum[b] - psum[a - 1];
}

int solve1() {
	int ret = 0;

	for(int i=0; i<N; i++)
		for (int j = i; j < N; j++) {
			if (rangeSum(i, j) % K == 0)
				ret++;
		}
	return ret % MOD;
}

int solve2(int end) {
	if (end < 0) return 0;

	int ret = 0;

	for (int j = end; j >= 0; j--) {
		if (rangeSum(j, end) % K == 0) {
			ret += solve2(j - 1) + 1;
			break;
		}
	}

	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input17_2.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		instream >> N >> K;

		int in;
		for (int j = 0; j < N; j++) {
			instream >> in;
			box.push_back(in);
		}

		psum = calcPsum(box);

		int ans1 = solve1();
		int ans2 = solve2(N-1);

		std::cout << ans1 << " " << ans2 << std::endl;

		box.clear();
		psum.clear();
	}

	instream.close();

	system("pause");
}