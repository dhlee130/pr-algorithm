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

const int EMPTY = -987654321;
int n, board[50];
int cache[50][50];

int play(int left, int right) {
	if (left > right) return 0;

	int &ret = cache[left][right];
	if (ret != EMPTY) return ret;

	ret = std::max(board[left] - play(left + 1, right)
		, board[right] - play(left, right - 1));

	if (right - left >= 1) {
		ret = std::max(ret, -play(left + 2, right));
		ret = std::max(ret, -play(left, right - 2));
	}
	return ret;
}


void main()
{
	
	std::ifstream instream;
	int numtestcases;

	instream.open("input9_17.txt");
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
			instream >> board[j];

		for (int j = 0; j < 50; j++)
			for (int k = 0; k < 50; k++)
				cache[j][k] = EMPTY;

		int ans = play(0, n - 1);

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}