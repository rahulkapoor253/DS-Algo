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

bool computeMirrorImage(struct Node* root_x, struct Node* root_y) {

//then root was a leaf node and is symmetric
	if (root_x == NULL && root_y == NULL) {
		return true;
	}
	else if (root_x != NULL && root_y != NULL) {
		//data should match, and its subtrees in mirror way
		return ( (root_x->data == root_y->data)
		         && computeMirrorImage(root_x->left, root_y->right)
		         && computeMirrorImage(root_x->right, root_y->left) );
	}

	return false;
}

bool isSymmetric(struct Node* root) {

	if (root == NULL) {
		return true;
	}

	if (root->left == NULL && root->right != NULL) {
		return false;
	}

	if (root->right == NULL && root->left != NULL) {
		return false;
	}

	return computeMirrorImage(root->left, root->right);
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(3);

	if (isSymmetric(root))
		cout << "Symmetric";
	else
		cout << "Not symmetric";

	return 0;
}
