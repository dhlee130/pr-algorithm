#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <stack>

void match(std::string formula) {
	std::stack<char> st;

	bool ret = true;

	for (int i = 0; i < formula.size(); i++) {
		char S = formula[i];
		if (S == '(' || S == '[' || S == '{')
			st.push(S);
		else {
			if (st.empty()) {
				ret = false;
				break;
			}

			char O = st.top();
			if (S == ')' && O != '(') {
				ret = false;
				break;
			}
			if (S == ']' && O != '[') {
				ret = false;
				break;
			}
			if (S == '}' && O != '{') {
				ret = false;
				break;
			}
			st.pop();
		}
	}

	if (!st.empty()) ret = false;

	if (ret) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
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

		match(formula);
	}

	instream.close();

	system("pause");
}