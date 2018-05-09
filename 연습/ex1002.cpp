#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <algorithm>

int solve(int x1, int y1, int r1, int x2, int y2, int r2) {
	double disXY = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	double dis = r1 + r2;

	if (x1 == x2 && y1 == y2) {
		if (disXY == dis)
			return -1;
		else
			return 0;
	}

	if (disXY < r1 || disXY < r2) {
		double longR = std::max(r1, r2);
		double shortR = std::min(r1, r2);
		if (longR == disXY + shortR) return 1;
		if (longR > disXY + shortR) return 0;
		if (longR < disXY + shortR) return 2;
	}

	if (disXY > dis) return 0;
	if (disXY == dis) return 1;
	if (disXY < dis) return 2;
}

void main() {
	int numTestCase;

	std::cin >> numTestCase;

	while (numTestCase--) {
		int x1, y1, r1, x2, y2, r2;

		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int ans = solve(x1, y1, r1, x2, y2, r2);

		std::cout << ans << std::endl;
		
	}

	system("pause");
}