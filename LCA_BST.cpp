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

struct Node* findLCA(struct Node* root, int x, int y) {

//if it lies on 1 side, then to find it by traversing, else root is the LCA
	while (root->data < x || root->data > y) {

		while (root->data < x) {
			root = root->right;
		}

		while (root->data > y) {
			root = root->left;
		}

	}

	return root;
}

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	struct Node *root = newNode(19);
	root->left        = newNode(7);
	root->left->left        = newNode(3);
	root->left->left->left        = newNode(2);
	root->left->left->right        = newNode(5);
	root->left->right        = newNode(11);
	root->left->right->right        = newNode(17);
	root->left->right->right->left        = newNode(13);
	root->right       = newNode(43);
	root->right->right       = newNode(47);
	root->right->right->right       = newNode(53);
	root->right->left  = newNode(23);
	root->right->left->right = newNode(37);
	root->right->left->right->left = newNode(29);
	root->right->left->right->right = newNode(41);
	root->right->left->right->left->right = newNode(31);

	int x = 7;
	int y = 13;

	struct Node* res = findLCA(root, x, y);
	cout << res->data << endl;

	return 0;
}

