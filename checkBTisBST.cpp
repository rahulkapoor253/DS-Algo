#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

struct Node* newNode(int val) {

	struct Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

bool isBST(struct Node* root, struct Node* temp_left, struct Node* temp_right) {

	if (root == NULL) {
		//empty BT will be a BST
		return true;
	}

	//check for boundary of BT being BST
	if (temp_left != NULL && temp_left->data > root->data) {
		return false;
	}

	if (temp_right != NULL && temp_right->data < root->data) {
		return false;
	}

	bool lst = isBST(root->left, temp_left, root);
	bool rst = isBST(root->right, root, temp_right);

	return lst && rst;
}

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	struct Node *root = newNode(3);
	root->left        = newNode(2);
	root->right       = newNode(5);
	root->left->left  = newNode(1);
	root->left->right = newNode(4);

	if (isBST(root, NULL, NULL))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;
}

