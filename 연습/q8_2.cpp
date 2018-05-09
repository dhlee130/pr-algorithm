#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>

bool match(std::string input, std::string value) {
	int pos = 0;
	
	while (pos < input.size() && pos < value.size()
		&& (input[pos] == '?' || input[pos] == value[pos]))
		pos++;
	
	if (pos == value.size())
		return pos == input.size();

	if (input[pos] == '*') {
		for (int skip = 0; pos + skip <= value.size(); skip++)
			if (match(input.substr(pos + 1), value.substr(pos + skip)))
				return true;
	}

	return false;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input8_2.txt");
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

		
		int num;

		instream >> num;

		std::vector<std::string> wildCard;

		while (num--) {
			std::string in;
			instream >> in;
			wildCard.push_back(in);
			}

		for (int j = 0; j < wildCard.size(); j++) {
			if (match(input, wildCard[j]))
				std::cout << wildCard[j] << std::endl;
		}


	}

	instream.close();

	system("pause");
}