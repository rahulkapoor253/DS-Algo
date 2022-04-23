#include <bits/stdc++.h>

using namespace std;

class Node {

	int data;
	Node* left;
	Node* right;

public:
	Node();
	Node(int val);
	Node* insertData(Node* root, int val);
	void printInorder(Node* root);
	Node* searchKey(Node* root, int key);

};

Node:: Node() {
//do nothing
}

Node:: Node(int val) {
	data = val;
	left = NULL;
	right = NULL;
}

Node* Node:: insertData(Node* root, int val) {

	if (root == NULL) {
		return new Node(val);
	}

	if (val > root->data) {
		root->right = insertData(root->right, val);
	}
	else {
		root->left = insertData(root->left, val);
	}

	return root;
}

void Node:: printInorder(Node* root) {

	if (root == NULL) {
		return;
	}

	printInorder(root->left);
	cout << root->data << endl;
	printInorder(root->right);

}

Node* Node:: searchKey(Node* root, int key) {

	if (root == NULL || root->data == key) {
		return root;
	}

	if (key < root->data) {
		return searchKey(root->left, key);
	}

	return searchKey(root->right, key);
}

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Node b;
	Node* root = NULL;

	root = b.insertData(root, 50);
	b.insertData(root, 30);
	b.insertData(root, 20);
	b.insertData(root, 40);
	b.insertData(root, 70);
	b.insertData(root, 60);
	b.insertData(root, 80);

	//b.printInorder(root);
	int key = 30;
	Node* temp = b.searchKey(root, key);

	if (temp) {
		cout << "Found" << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	return 0;
}

