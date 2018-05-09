#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <cstdio>
#include <cstring>
#include <algorithm>



int solve(int num) {
	if (num < 3) return num;
	num -= 2;
	int ret = 3;
	int i = 2;
	while (num > 0) {
		if (num - i <= 0)
			return ret;
		else if (num - 2 * i <= 0)
			return ++ret;

		num -= 2*i;
		i++;
		ret += 2;
		
	}

	return ret;
}

int main() {
	int numTestCase;

	std::cin >> numTestCase;

	while (numTestCase--) {
		int num1, num2;

		std::cin >> num1 >> num2;

		int num = num2 - num1;

		int ans = solve(num);

		std::cout << ans << std::endl;
	}

	system("pause");
}