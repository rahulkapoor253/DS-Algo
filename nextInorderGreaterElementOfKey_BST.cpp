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

struct Node* findNextGreaterInorder(struct Node* root, int key) {
	//find the key element
	struct Node* temp = root;

	while (temp != NULL) {

		if (temp->data == key) {
			break;
		}
		else if (temp->data > key) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}

	}

	//now my temp is pointed to the key
	if (temp->right == NULL) {
		return temp;
	}

	struct Node* res = temp->right;
	while (res->left != NULL) {
		res = res->left;
	}

	return res;
}

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	struct Node *root = newNode(19);
	root->left        = newNode(7);
	root->right       = newNode(43);
	root->right->left  = newNode(23);
	root->right->left->right = newNode(37);
	root->right->left->right->left = newNode(29);
	root->right->left->right->right = newNode(41);

	int key = 23;
	struct Node* res = findNextGreaterInorder(root, key);
	cout << res->data << endl;

	return 0;
}

