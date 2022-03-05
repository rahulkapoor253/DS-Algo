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

void computeInorderTraversal(struct Node* root, vector<int> &vec) {

//base case
	if (root == NULL) {
		return;
	}

	computeInorderTraversal(root->left, vec);

	vec.push_back(root->data);

	computeInorderTraversal(root->right, vec);

}

void computeInorderKthNode(struct Node* root, int k) {

//compute inorder traversal and store it in a vec
	vector<int> vec;

	computeInorderTraversal(root, vec);

	cout << vec[k - 1] << endl;

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

	int k = 3;

	computeInorderKthNode(root, k);

	return 0;
}
