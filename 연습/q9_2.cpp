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

std::vector<std::string> items;
std::vector<int> volume, need;
int capacities, n;

int cache[1001][101];

int pack(int capacity, int item) {
	if (item == n) return 0;

	int& ret = cache[capacity][item];
	if (ret != -1) return ret;

	ret = pack(capacity, item + 1);

	if (capacity >= volume[item])
		ret = std::max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}

void reconstruct(int capacity, int item, std::vector<std::string>& picked) {
	if (item == n) return;
	if (pack(capacity, item) == pack(capacity, item + 1))
		reconstruct(capacity, item + 1, picked);
	else {
		picked.push_back(items[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input9_2.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		instream >> n >> capacities;

		std::string in1;
		int in2, in3;

		for (int i = 0; i < n; i++) {
			instream >> in1 >> in2 >> in3;
			items.push_back(in1);
			volume.push_back(in2);
			need.push_back(in3);
		}

		memset(cache, -1, sizeof(cache));

		int ans = pack(capacities, 0);
		std::vector<std::string> picked;
		reconstruct(capacities, 0, picked);

		std::cout << ans << " " << picked.size() << std::endl;

		for (int j = 0; j < picked.size(); j++)
			std::cout << picked[j] << std::endl;

		items.clear();
		volume.clear();
		need.clear();

	}

	instream.close();

	system("pause");
}