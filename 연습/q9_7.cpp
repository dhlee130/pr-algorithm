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

int N, K;
int cache[501], cache2[501];
std::vector<int> arr;
const int MAX = 200000000 + 1;
int lis(int start) {
	int& ret = cache[start + 1];

	if (ret != -1) return ret;

	ret = 1;

	for (int next = start + 1; next < N; next++) {
		if (start == -1 || arr[start] < arr[next])
			ret = std::max(ret, lis(next) + 1);
	}
	return ret;
}

int count(int start) {
	if (lis(start) == 1) return 1;

	int& ret = cache2[start + 1];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = start + 1; next < N; next++) {
		if ((start == -1 || arr[start] < arr[next]) &&
			lis(start) == lis(next) + 1)
			ret = std::min<long long>(MAX, (long long)ret + count(next));
	}
	return ret;
}

void reconstruct(int start, int skip, std::vector<int>& li) {
	if (start != -1) li.push_back(arr[start]);

	std::vector<std::pair<int, int> > followers;
	for (int next = start + 1; next < N; next++)
		if ((start == -1 || arr[start] < arr[next]) &&
			lis(start) == lis(next) + 1)
			followers.push_back(std::make_pair(arr[next], next));
	std::sort(followers.begin(), followers.end());

	for (int i = 0; i < followers.size(); i++) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip)
			skip -= cnt;
		else {
			reconstruct(idx, skip, li);
			break;
		}
	}
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input9_7.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		instream >> N >> K;
		int in;
		for (int j = 0; j < N; j++) {
			instream >> in;
			arr.push_back(in);
		}

		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));

		int ans = lis(-1) -1;

		std::vector<int> li;
		reconstruct(-1, K - 1, li);

		std::cout << ans << std::endl;
		for (int j = 0; j < li.size(); j++)
			std::cout << li[j] << " ";
		std::cout << std::endl;

		arr.clear();
	}

	instream.close();

	system("pause");
}