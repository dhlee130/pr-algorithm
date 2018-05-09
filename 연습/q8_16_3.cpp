#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>

int road[51][51];
int deg[51];

int N, D, P, Q;

double cache[51][101];

double search3(int here, int days) {
	if (days == 0) return (here == P ? 1.0 : 0.0);

	double& ret = cache[here][days];
	if (ret > -0.5) return ret;

	ret = 0.0;
	for (int there = 0; there < N; there++) {
		if (road[here][there] == 1)
			ret += search3(there, days - 1) / deg[there];
	}
	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input8_16.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{


		instream >> N >> D >> P;

		int num;
		
		memset(deg, 0, sizeof(deg));

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++) {
				instream >> num;
				road[j][k] = num;
				if (num == 1) deg[j] += 1;
			}

		instream >> num;

		std::vector<int> out;
		int in;
		while (num--) {
			instream >> in;
			out.push_back(in);
		}

		for (int j = 0; j < out.size(); j++) {
			Q = out[j];

			memset(cache, -1, sizeof(cache));

			double ans = search3(Q, D);
			
			std::cout.setf(std::ios::fixed);
			
			std::cout.precision(8);
			std::cout << ans << " ";
		}

		std::cout << std::endl;
	}

	instream.close();

	system("pause");
}