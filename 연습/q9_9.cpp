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

void curve(std::string seed, int generation) {
	if (generation == 0) {
		std::cout << seed;
		return;
	}

	for (int i = 0; i < seed.size(); i++) {
		if (seed[i] == 'X')
			curve("X+YF", generation - 1);
		else if (seed[i] == 'Y')
			curve("FX-Y", generation - 1);
		else
			std::cout << seed[i];
	}
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input9_9.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		int generation, p, l;

		instream >> generation >> p >> l;

		std::string seed = "FX";

		curve(seed, generation);
		std::cout << std::endl;
	}

	instream.close();

	system("pause");
}