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

struct Comparator {
	const std::vector<int>& group;
	int t;

	Comparator(const std::vector<int>& _group, int _t) : group(_group),
		t(_t) {}
	

	bool operator () (int a, int b) {
		if (group[a] != group[b]) return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

std::vector<int> getSuffixArray(const std::string& s) {
	int n = s.size();

	int t = 1;
	std::vector<int> group(n + 1);

	for (int i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1;

	std::vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;

	while (t < n) {
		Comparator compareUsing2T(group, t);
		std::sort(perm.begin(), perm.end(), compareUsing2T);

		t *= 2;
		if (t >= n) break;

		std::vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;

		for (int i = 1; i < n; i++)
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		group = newGroup;
	}
	return perm;
}

int commonPrefix(const std::string& s, int i, int j) {
	int k = 0;
	while (i < s.size() && j < s.size() && s[i] == s[j]) {
		++i; ++j; ++k;
	}
	return k;
}

int longestFrequent(int k, const std::string& s) {
	std::vector<int> a = getSuffixArray(s);
	int ret = 0;
	for (int i = 0; i + k <= s.size(); i++)
		ret = std::max(ret, commonPrefix(s, a[i], a[i + k - 1]));
	return ret;
}


void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input20_6.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		int k;
		std::string s;

		instream >> k >> s;

		int ans = longestFrequent(k, s);

		std::cout << ans << std::endl;

	}

	instream.close();

	system("pause");
}