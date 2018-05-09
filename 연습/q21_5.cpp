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

struct TreeNode {
	std::vector<TreeNode*> children;
};

int longest;

int height(TreeNode* root) {
	std::vector<int> heights;

	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));

	if (heights.empty()) return 0;
	std::sort(heights.begin(), heights.end());

	if (heights.size() >= 2)
		longest = std::max(longest, 2 +
			heights[heights.size() - 2] + heights[heights.size() - 1]);

	return heights.back() + 1;
}

int solve(TreeNode* root) {
	longest = 0;

	int h = height(root);

	return std::max(longest, h);
}

int n, x[100], y[100], r[100];

int sqr(int x) {
	return x*x;
}

int sqrdist(int a, int b) {
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool enclose(int a, int b) {
	return r[a] > r[b] && sqrdist(a, b) < sqr(r[a] - r[b]);
}

bool isChild(int parent, int child) {
	if (!enclose(parent, child)) return false;
	for (int i = 0; i < n; i++)
		if (i != parent && i != child &&
			enclose(parent, i) && enclose(i, child)) return false;
	return true;
}

TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ch++)
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	return ret;
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input21_5.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		

		instream >> n;

		for (int i = 0; i < n; i++)
			instream >> x[i] >> y[i] >> r[i];

		TreeNode* root = getTree(0);

		
			
		
		int ans = solve(root);

		std::cout << ans << std::endl;
	}

	instream.close();

	system("pause");
}