#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>

int solve(std::vector<int>& idol, std::vector<int>& fan) {

	int ret = 0;

	for (int i = 0; i < (fan.size() - idol.size() + 1); i++) {
		int sum = 0;
		for (int j = 0; j < idol.size(); j++) {
			sum += idol[j] * fan[j + i];
		}
		if (sum == 0)
			ret++;
	}

	return ret;
}


void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input7_7.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	
	
	for (int i = 0; i < numtestcases; i++)
	{
		std::string in1, in2;
		instream >> in1 >> in2;

		std::vector<int> idol, fan;

		for (int j = 0; j < in1.size(); j++) {
			if (in1[j] == 'F')
				idol.push_back(0);
			else
				idol.push_back(1);
		}

		for (int j = 0; j < in2.size(); j++) {
			if (in2[j] == 'F')
				fan.push_back(0);
			else
				fan.push_back(1);
		}

		int ans = solve(idol, fan);

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}