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

std::vector<int> getPartialMatch(const std::string& N) {
	int m = N.size();
	std::vector<int> pi(m, 0);

	int begin = 1, matched = 0;

	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

std::vector<int> kmpSearch(const std::string& H, const std::string& N) {
	int n = H.size(), m = N.size();
	std::vector<int> ret;

	std::vector<int> pi = getPartialMatch(N);

	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && H[begin + matched] == N[matched]) {
			matched++;
			
			if (matched == m) ret.push_back(begin);
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}



int shifts(const std::string& origin, const std::string& tar) {
	return kmpSearch(origin + origin, tar)[0];
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input20_4.txt");
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

		std::string original, target;

		instream >> original;

		int ans = 0;
		

		for (int j = 0; j < num; j++) {
			instream >> target;
			if (j % 2 == 1) {
				ans += shifts(original, target);
				original = target;
			}
			else {
				ans += shifts(target, original);
				original = target;
			}
			
		}

		std::cout << ans << std::endl;

	}

	instream.close();

	system("pause");
}