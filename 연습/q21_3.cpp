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
#include <random>

std::vector<int> slice(std::vector<int> vec, int a, int b) {
	return std::vector<int>(vec.begin() + a, vec.begin() + b);
}



void printPostOrder(std::vector<int> pre, std::vector<int> in) {
	
	const int N = pre.size();

	if (pre.empty()) return;

	const int root = pre[0];

	const int L = std::find(in.begin(), in.end(), root) - in.begin();
	const int R = N - L - 1;

	printPostOrder(slice(pre, 1, L + 1), slice(in, 0, L));
	printPostOrder(slice(pre, L + 1, N), slice(in, L + 1, N));

	std::cout << root << " ";
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input21_3.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		int N;

		instream >> N;

		int num;

		std::vector<int> pre, in;
		for (int i = 0; i < N; i++) {
			instream >> num;
			pre.push_back(num);
		}
		for (int i = 0; i < N; i++) {
			instream >> num;
			in.push_back(num);
		}

		printPostOrder(pre, in);
		std::cout << std::endl;
	}

	instream.close();

	system("pause");
}