#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <cstdio>
#include <cstring>
#include <algorithm>

int cache0[41];
int solve0(int num) {
	if (num == 0)
		return 1;
	if (num == 1)
		return 0;

	int& ret = cache0[num];
	if (ret != -1) return ret;

	return ret = solve0(num - 2) + solve0(num - 1);
}

int cache1[41];
int solve1(int num) {
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;

	int& ret = cache1[num];
	if (ret != -1) return ret;

	return ret = solve1(num - 2) + solve1(num - 1);
}

int main() {
	int numTestCase;

	std::cin >> numTestCase;

	while (numTestCase--) {
		int num;

		std::cin >> num;

		memset(cache0, -1, sizeof(cache0));
		memset(cache1, -1, sizeof(cache1));
		int ans0 = solve0(num);
		int ans1 = solve1(num);
		
		std::cout << ans0 << " " << ans1 << std::endl;
	}

	system("pause");
}