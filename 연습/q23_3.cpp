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

int a, b, n;

struct RNG {
	int num;
	RNG() : num(1983) {}
	int next() {
		int ret = num;
		num = (num * (long long)a + b) % 20090711;
		return ret;
	}
};

int sumMedian(int n, RNG rng) {
	std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	int ret = 0;

	for (int cnt = 0; cnt < n; cnt++) {
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());

		if (!minHeap.empty() && !maxHeap.empty() &&
			minHeap.top() < maxHeap.top()) {
			int n1 = maxHeap.top(), n2 = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(n2);
			minHeap.push(n1);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}

	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input23_3.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		instream >> n >> a >> b;

		RNG rng;

		int ans = sumMedian(n, rng);

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}