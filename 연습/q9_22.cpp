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

int n, m, price[20], pref[20];
int c[201];

int sushi() {
	int ret = 0;
	c[0] = 0;

	for (int budget = 1; budget <= m; budget++) {
		int cand = 0;
		for (int dish = 0; dish < n; dish++)
			if (budget >= price[dish])
				cand = std::max(cand, c[(budget - price[dish]) % 201] + pref[dish]);
		c[budget % 201] = cand;
		ret = std::max(ret, cand);
	}
	return ret;
}


void main()
{
	
	std::ifstream instream;
	int numtestcases;

	instream.open("input9_22.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	

	for (int i = 0; i < numtestcases; i++)
	{
		instream >> n >> m;

		m /= 100;

		int pricein;

		for (int i = 0; i < n; i++) {
			instream >> pricein >> pref[i];

			pricein /= 100;

			price[i] = pricein;
		}

		int ans = sushi();

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}