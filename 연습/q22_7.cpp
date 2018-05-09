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
#include <map>

//트립구현
typedef int KeyType;

struct Node {
	KeyType key;

	int priority, size;

	Node *left, *right;

	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL)
		,right(NULL) {}

	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }

	void calcSize() {
		size = 1;
		if(left) size += left->size;
		if (right) size += right->size;
	}
};

typedef std::pair<Node*, Node*> NodePair;

NodePair split(Node *root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);

	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;

	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}

Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

Node* erase(Node* root, KeyType key) {
	if (root == NULL) return root;

	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}

	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}

Node* kth(Node* root, int k) {
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}

int n, shifted[50000];
int A[50000];

void solve() {
	Node* candidates = NULL;
	for (int i = 0; i < n; i++)
		candidates = insert(candidates, new Node(i + 1));

	

	for (int i = n - 1; i >= 0; i--) {
		int larger = shifted[i];
		Node* k = kth(candidates, i + 1 - larger);
		
		A[i] = k->key;
		candidates = erase(candidates, k->key);
		
	}
}

void main()
{
	std::ifstream instream;
	int numtestcases;

	instream.open("input22_7.txt");
	if (instream.fail())
	{
		std::cerr << "Input file opening failed\n";
		exit(1);
	}

	instream >> numtestcases;



	for (int i = 0; i < numtestcases; i++)
	{
		instream >> n;

		for (int j = 0; j < n; j++)
			instream >> shifted[j];

		solve();

		for (int j = 0; j < n; j++)
			std::cout << A[j] << " ";

		std::cout << std::endl;
	}

	instream.close();

	system("pause");
}