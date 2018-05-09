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

const int MAX = 1000000000 + 1;
int length[51];

void precalc() {
	length[0] = 1;
	for (int i = 1; i <= 50; i++)
		length[i] = std::min(MAX, length[i - 1] * 2 + 2);
}

const std::string EXPAND_X = "X+YF";
const std::string EXPAND_Y = "FX-Y";

char expand(const std::string& dragonCurve, int generation, int skip) {
	if (generation == 0) {
		assert(skip < dragonCurve.size());
		return dragonCurve[skip];
	}

	for (int i = 0; i < dragonCurve.size(); i++) 
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= length[generation])
				skip -= length[generation];
			else if (dragonCurve[i] == 'X')
				return expand(EXPAND_X, generation - 1, skip);
			else
				return expand(EXPAND_Y, generation - 1, skip);
		}

		else if (skip > 0)
			skip--;
		else
			return dragonCurve[i];
	

	return '#';
}


void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input9_9_2.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	precalc();

	for (int i = 0; i < numtestcases; i++)
	{
		int generation, p, l;

		instream >> generation >> p >> l;

		std::string seed = "FX";

		for (int j = 0; j < l; j++) {
			char out = expand(seed, generation, p + j-1);
			std::cout << out;
		}

		std::cout << std::endl;
	}

	instream.close();

	system("pause");
}