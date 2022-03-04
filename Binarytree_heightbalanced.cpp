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

int findHeight(struct Node* root) {

	if (root == NULL) {
		return 0;
	}

	int lh = findHeight(root->left);
	int rh = findHeight(root->right);

	return 1 + max(lh, rh);
}

//height balanced comes up when our BT is perfect BT or complete BT
//where difference of a Node's LST and RST <=1
bool isBalanced(struct Node* root) {

//leaf node is a balanced binary tree
	if (root == NULL) {
		return true;
	}

	int left_height, right_height;

	left_height = findHeight(root->left);
	right_height = findHeight(root->right);

//this node is height balanced and all subsequent nodes
	if ( abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right) ) {
		return true;
	}

	return false;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(8);

	if (isBalanced(root))
		cout << "Tree is balanced";
	else
		cout << "Tree is not balanced";

	return 0;
}
