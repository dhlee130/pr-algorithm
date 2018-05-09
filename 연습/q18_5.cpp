#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>

void josephus(int n, int k) {
	std::list<int> survivors;;

	for (int i = 1; i <= n; i++)
		survivors.push_back(i);

	std::list<int>::iterator kill = survivors.begin();
	
	while (n > 2) {
		kill = survivors.erase(kill);
		if (kill == survivors.end()) kill = survivors.begin();
		n--;

		for (int i = 0; i < k - 1; i++) {
			kill++;
			if (kill == survivors.end()) kill = survivors.begin();
		}
	}

	std::cout << survivors.front() << " " << survivors.back() << std::endl;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input18_5.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		int N, K;

		instream >> N >> K;

		josephus(N, K);


	}

	instream.close();

	system("pause");
}