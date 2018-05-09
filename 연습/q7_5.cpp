#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>



int solve(std::vector<int>& h, int left, int right) {
	if (left == right) return h[left];

	int mid = (left + right) / 2;

	int ret = std::max(solve(h, left, mid), solve(h, mid + 1, right));

	int lo = mid, hi = mid + 1;
	int height = std::min(h[lo], h[hi]);

	ret = std::max(ret, height * 2);

	while (left < lo || hi < right) {

		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			hi++;
			height = std::min(height, h[hi]);
		}
		else {
			lo--;
			height = std::min(height, h[lo]);
		}

		ret = std::max(ret, height*(hi - lo + 1));
	}

	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input7_5.txt");
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

		std::vector<int> height;
		int val;
		for (int j = 0; j < num; j++) {
			instream >> val;
			height.push_back(val);
		}

		int ans = solve(height, 0, height.size()-1);

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}