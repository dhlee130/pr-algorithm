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

double search(std::vector<int>& path) {
	if (path.size() == D + 1) {
		if (path.back() != Q) return 0.0;

		double ret = 1;

		for (int i = 0; i + 1 < path.size(); i++)
			ret /= deg[path[i]];
		return ret;
	}

	double ret = 0;
	for (int there = 0; there < N; there++) {
		if (road[path.back()][there]) {
			path.push_back(there);
			ret += search(path);
			path.pop_back();
		}
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

			std::vector<int> path;

			path.push_back(P);

			double ans = search(path);
			
			std::cout.setf(std::ios::fixed);
			
			std::cout.precision(8);
			std::cout << ans << " ";
		}

		std::cout << std::endl;
	}

	instream.close();

	system("pause");
}