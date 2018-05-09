#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>

#define min(a,b) ((a)<(b)) ? a : b;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(const std::vector<int>& clocks) {
	bool ret = true;

	for (int i = 0; i < 16; i++)
		if (clocks[i] != 12) ret = false;

	return ret;
}

void push(std::vector<int>& clocks, int switc) {
	for (int clock = 0; clock < CLOCKS; clock++) {
		if (linked[switc][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

int solve(std::vector<int>& clocks, int switc) {
	if (switc == SWITCHES) return areAligned(clocks) ? 0 : INF;

	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + solve(clocks, switc + 1));
		push(clocks, switc);
	}

	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input6_8.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	

	for (int i = 0; i < numtestcases; i++)
	{
		std::vector<int> clocks;

		int num;

		for (int j = 0; j < CLOCKS; j++) {
			instream >> num;
			clocks.push_back(num);
		}

		int ans = INF;

		for (int j = 0; j < SWITCHES; j++) {
			ans = min(ans, solve(clocks, j));
			
		}

		std::cout << ans << std::endl;
		
	}

	instream.close();

	system("pause");
}