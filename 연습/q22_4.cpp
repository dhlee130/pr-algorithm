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

std::map<int, int> coords;

bool isDominated(int x, int y) {

	std::map<int, int>::iterator it = coords.lower_bound(x);

	if (it == coords.end()) return false;

	return y < it->second;
}

void removeDominated(int x, int y) {

	std::map<int, int>::iterator it = coords.lower_bound(x);

	if (it == coords.begin()) return;
	--it;

	while (true) {
		if (it->second > y) break;

		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			std::map<int, int>::iterator jt = it;
			jt--;
			coords.erase(it);
			it = jt;
		}
	}
}

int registered(int x, int y) {
	if (isDominated(x, y)) return coords.size();

	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input22_4.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		coords.clear();
		int num;

		instream >> num;

		int ans = 0;

		for (int i = 0; i < num; i++) {
			int x, y;
			instream >> x >> y;
			ans += registered(x, y);
		}

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}