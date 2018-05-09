#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

const int coverType[4][3][2] = {
	{ {0,0}, {1,0}, {0,1} },
	{ {0,0}, {0,1}, {1,1} },
	{ {0,0}, {1,0}, {1,1} },
	{ {0,0}, {1,0}, {1,-1}}
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}

	return ok;
}

int cover(vector<vector<int>>& board) {

	int y = -1, x = -1;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++)
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		if (y != -1) break;
	}

	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++)
	{
		if (set(board, y, x, type, 1))
			ret += cover(board);

		set(board, y, x, type, -1);
	}

	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input6_5.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;

	for (int i = 0; i < numtestcases; i++)
	{
		int row, column;
		instream >> row >> column;

		std::vector<vector<int>> board;

		for (int i = 0; i < row; i++)
		{
			std::vector<int> temp;
			temp.resize(column);
			board.push_back(temp);
		}
		char input;

		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < column; k++)
			{
				instream >> input;

				if (input == '#')
					board[j][k] = 1;
				else
					board[j][k] = 0;
			}
		}

		/*for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < column; k++)
			{
				cout << board[j][k];
			}
			cout << endl;
		}*/

		int ans = cover(board);
		
		cout << ans << endl;
	}

	instream.close();

	system("pause");
}