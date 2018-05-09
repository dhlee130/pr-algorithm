#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>


std::string reverse(std::string::iterator& it) {
	char head = *(it++);

	if (head == 'w' || head == 'b')
		return std::string(1, head);
	std::string upperLeft = reverse(it);
	std::string upperRight = reverse(it);
	std::string lowerLeft = reverse(it);
	std::string lowerRight = reverse(it);

	return std::string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input7_3_2.txt");
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

		std::string ans = reverse(iter);

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}