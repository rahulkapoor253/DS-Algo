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

void printLeftBoundary(struct Node* root) {

	if (root == NULL) {
		return;
	}

	if (root->left != NULL) {

		cout << root->data << " ";
		printLeftBoundary(root->left);

	}
	else if (root->right != NULL) {

		cout << root->data << " ";
		printLeftBoundary(root->right);

	}

	//do nothing for the leftmost leaf node as it will be covered later

}

void printRightBoundary(struct Node* root) {

	if (root == NULL) {
		return;
	}

//should be done in bottom-up manner
	if (root->right != NULL) {

		printLeftBoundary(root->right);
		cout << root->data << " ";

	}
	else if (root->left != NULL) {

		printLeftBoundary(root->left);
		cout << root->data << " ";

	}

	//do nothing for the rightmost leaf node as it will be covered later

}

void printLeaves(struct Node* root) {

//try preorder traversal for leave node
	if (root == NULL) {
		return;
	}

	if (root->left == NULL && root->right == NULL) {
		cout << root->data << " ";
	}

	printLeaves(root->left);
	printLeaves(root->right);

}

void printBoundary(struct Node* root) {

	if (root == NULL) {
		return;
	}

	cout << root->data << " ";

	//print Left boundary
	printLeftBoundary(root->left);

	//print leaves from left to right
	printLeaves(root->left);
	printLeaves(root->right);

	//print right bounday = bottom-up manner
	printRightBoundary(root->right);

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	struct Node* root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);

	printBoundary(root);

	return 0;
}
