#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>



int countingPairs(bool taken[10], bool areFriends[10][10], int n) {

	int firstFree = -1;

	for (int i = 0; i < n; i++)
	{
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		if (!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += countingPairs(taken, areFriends, n);
			taken[firstFree] = taken[pairWith] = false;
		}

	}
	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input6_4.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	for (int i = 0; i<numtestcases; i++)
	{
		int student, pairs;

		instream >> student;
		instream >> pairs;

		bool areFriends[10][10] = { false };
		bool taken[10] = { false };
		
		
		for (int j = 0; j < pairs; j++)
		{
			int f1, f2;
			instream >> f1 >> f2;
			areFriends[f1][f2] = true;
			areFriends[f2][f1] = true;
		}

		int ret = countingPairs(taken,areFriends, student);

		std::cout << ret << "\n";
	}

	instream.close();

	system("pause");
}

