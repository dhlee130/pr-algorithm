#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <stack>

bool wellMatch(const std::string formula) {
	
	const std::string opening("({["), closing(")}]");

	std::stack<char> openStack;

	for (int i = 0; i < formula.size(); i++) {
		if (opening.find(formula[i]) != -1)
			openStack.push(formula[i]);

		else {
			if (openStack.empty()) return false;

			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;

			openStack.pop();
		}
	}

	return openStack.empty();
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input19_5.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		std::string formula;

		instream >> formula;

		if (wellMatch(formula)) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}

	instream.close();

	system("pause");
}