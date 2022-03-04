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

void printInorder(struct Node* root) {

	if (root == NULL) {
		return;
	}

	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);

}

void printPreorder(struct Node* root) {

	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);

}

void printPostorder(struct Node* root) {

	if (root == NULL) {
		return;
	}

	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->data << " ";

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}
