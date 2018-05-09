#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>

bool jump(std::vector<std::vector<int>> & board, int y, int x) {
	if (y == (board.size()-1) && x == (board[0].size()-1)) return true;
	if (y >= board.size() || x >= board[0].size()) return false;
	
	int num = board[y][x];

	return jump(board, y + num, x) || jump(board, y, x + num);
}

int cache[100][100];

int jumpWithMemory(std::vector<std::vector<int>>& board, int y, int x) {
	if (y == (board.size() - 1) && x == (board[0].size() - 1)) return 1;
	if (y >= board.size() || x >= board[0].size()) return 0;

	int& ret = cache[y][x];

	if (ret != -1) return ret;
	int num = board[y][x];

	return ret = jumpWithMemory(board, y + num, x) || jumpWithMemory(board, y, x + num);
}

int solve(std::vector<std::vector<int>>& board, int y, int x) {
	if (y == (board.size() - 1) && x == (board[0].size() - 1)) return 1;
	if (y >= board.size() || x >= board[0].size()) return 0;

	int num = board[y][x];
	int ret = 0;
	for (int i = 0; i <= num; i++) {
		ret += solve(board, y + i, x + num - i);
	}

	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input8.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	
	
	for (int i = 0; i < numtestcases; i++)
	{
		int x, y;
		instream >> x >> y;

		std::vector<std::vector <int>> board;
		board.assign(y, std::vector<int>(x));

		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				instream >> board[j][k];
			}
		}

		

		bool ans = jump(board, 0, 0);

		std::cout << ans << std::endl;

		memset(cache, -1, sizeof(cache));

		int ans2 = jumpWithMemory(board, 0, 0);

		std::cout << ans2 << std::endl;

		int ans3 = solve(board, 0, 0);
		std::cout << ans3 << std::endl;
	}

	instream.close();

	system("pause");
}