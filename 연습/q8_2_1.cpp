#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>

std::string W, S;

int cache[101][101];

bool matchMemorized(int w, int s) {
	
	int& ret = cache[w][s];
	if (ret != -1) return ret;

	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		w++;
		s++;
	}

	if (w == W.size()) return ret = (s == S.size());

	if (W[w] == '*') {
		for (int skip = 0; s + skip <= S.size(); skip++)
			if (matchMemorized(w + 1, s + skip))
				return ret = 1;
	}

	return ret = 0;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input8_2.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	
	
	for (int i = 0; i < numtestcases; i++)
	{
		

		instream >> W;

		
		int num;

		instream >> num;

		std::vector<std::string> wildCard;

		while (num--) {
			std::string in;
			instream >> in;
			wildCard.push_back(in);
			}

		for (int j = 0; j < wildCard.size(); j++) {
			memset(cache, -1, sizeof(cache));
			S = wildCard[j];
			if (matchMemorized(0,0))
				std::cout << S << std::endl;
		}


	}

	instream.close();

	system("pause");
}