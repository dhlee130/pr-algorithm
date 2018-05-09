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


int n;

std::vector<int> arr;

int concat(const std::vector<int>& lengths) {
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

	for (int i = 0; i < n; i++) {
		pq.push(lengths[i]);
	}
	int ret = 0;
	
	while (pq.size() > 1) {
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1 + min2);
		ret += min1 + min2;
	}

	return ret;
}

void main()
{
	
	std::ifstream instream;
	int numtestcases;

	instream.open("input10_4.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	

	for (int i = 0; i < numtestcases; i++)
	{
		instream >> n;
		int in;
		
		for (int j = 0; j < n; j++) {
			instream >> in;
			arr.push_back(in);
		}

		int ans = concat(arr);

		std::cout << ans << std::endl;

		arr.clear();
	}

	instream.close();

	system("pause");
}