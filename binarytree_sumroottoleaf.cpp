#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int val) {

	struct Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

int computeRootToLeafSum(struct Node* root, int res) {

	//base case
	if (root == NULL) {
		return 0;
	}

	res = res * 10 + root->data;

//when reached leaf node
	if (root->left == NULL && root->right == NULL) {
		return res;
	}

	int lst_sum = computeRootToLeafSum(root->left, res);
	int rst_sum = computeRootToLeafSum(root->right, res);

	return lst_sum + rst_sum;
}

int treePathsSum(struct Node* root) {

	int res = 0;

	int sum = computeRootToLeafSum(root, res);

	return sum;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Node *root = newNode(6);
	root->left = newNode(3);
	root->right = newNode(5);
	root->left->left = newNode(2);
	root->left->right = newNode(5);
	root->right->right = newNode(4);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(4);
	cout << "Sum of all paths is " << treePathsSum(root);

	return 0;
}
