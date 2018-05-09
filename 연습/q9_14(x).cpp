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

int k;
const int MAX_N = 15;
std::string word[MAX_N];

int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];

void precalc(int a, int b) {
	if (a == b) overlap[a][b] = word[a].size();
	
	else {
		int num = 0;
		int c = 0, d = 0;

		while (true) {
			c = word[a].find(word[b][0], d);
			d = c + 1;
			
			if (c == -1) break;
			int val = 0;
			for (int j = 0; c + j < word[a].size() && j < word[b].size(); j++)
				if (word[a][c + j] == word[b][j])
					val++;
				else
					break;
			num = std::max(val, num);
		}
		

		overlap[a][b] = num;
	}
}

int restore(int last, int used) {
	if (used == (1 << k) - 1) return 0;

	int& ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for(int next = 0; next < k; next++)
		if ((used & (1 << next)) == 0) {
			int cand = overlap[last][next] + restore(next, used + (1 << next));
			ret = std::max(ret, cand);
		}
	return ret;
}

std::string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return"";

	for (int next = 0; next < k; next++) {
		if (used & (1 << next)) continue;

		int ifUsed = restore(next, used + (1 << next)) +
			overlap[last][next];
		if (restore(last, used) == ifUsed)
			return (word[next].substr(overlap[last][next])+
				reconstruct(next, used + (1 << next)));
	}
	return "ooops";
}

void main()
{
	
	std::ifstream instream;
	int numtestcases;

	instream.open("input9_14.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	

	for (int i = 0; i < numtestcases; i++)
	{
		instream >> k;
		
		for (int j = 0; j < k; j++) {
			instream >> word[j];
		}

		for (int j = 0; j < k; j++)
			for (int l = 0; l < k; l++)
				precalc(j, l);

		int max = 0;
		int maxnum = 0;

		memset(cache, -1, sizeof(cache));

		for (int j = 0; j < k; j++) {
			if (max < restore(j, 1 << j)) {
				max = restore(j, 1 << j);
				maxnum = j;

			}
			
		}
		
		

		std::string out = reconstruct(maxnum, 1 << maxnum);

		std::cout << word[maxnum] << out << std::endl;
	}

	instream.close();

	system("pause");
}