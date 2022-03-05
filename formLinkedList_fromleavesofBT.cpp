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

void computePreorderTraversal(struct Node* root, list<Node*> &my_list) {

	//base case
	if (root == NULL) {
		return;
	}

//leave node case
	if (root->left == NULL && root->right == NULL) {
		my_list.push_back(root);
	}

	computePreorderTraversal(root->left, my_list);
	computePreorderTraversal(root->right, my_list);

}

void computeLeavesToLinkedList(struct Node* root) {

	list<Node*> my_list;

	computePreorderTraversal(root, my_list);

	for (auto itr = my_list.begin(); itr != my_list.end(); itr++) {
		cout << (*itr)->data << endl;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Node *head = NULL;
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	root->left->left->left = newNode(7);
	root->left->left->right = newNode(8);
	root->right->right->left = newNode(9);
	root->right->right->right = newNode(10);

	computeLeavesToLinkedList(root);

	return 0;
}
