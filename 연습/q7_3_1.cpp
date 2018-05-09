#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>

#define MAX_SIZE 16

char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(std::string::iterator& it, int y, int x, int size) {
	char head = *(it++);

	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; dy++)
			for (int dx = 0; dx < size; dx++)
				decompressed[y + dy][x + dx] = head;
	}

	else {
		int half = size / 2;
		decompress(it, y, x, half);
		decompress(it, y, x + half, half);
		decompress(it, y + half, x, half);
		decompress(it, y + half, x + half, half);
	}
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input7_3_1.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	
	
	for (int i = 0; i < numtestcases; i++)
	{
		

		std::string input;
		
		instream >> input;

		
		std::string::iterator iter = input.begin();

		decompress(iter, 0, 0, 16);

		for (int j = 0; j < MAX_SIZE; j++) {
			for (int k = 0; k < MAX_SIZE; k++)
				std::cout << decompressed[j][k];
			std::cout << std::endl;
		}
			

		std::cout << std::endl;
	}

	instream.close();

	system("pause");
}