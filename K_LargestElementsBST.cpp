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

//we can calculate reverse of Inorder traversal: Right, Root, Left
void findKLargest(struct Node* root, int k, vector<int> &res) {

	if (root != NULL && res.size() < k) {

		findKLargest(root->right, k, res);

		if (res.size() < k) {

			res.push_back(root->data);
			findKLargest(root->left, k, res);

		}

	}

}

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	struct Node *root = newNode(19);
	root->left        = newNode(7);
	root->right       = newNode(43);
	root->right->right       = newNode(47);
	root->right->right->right       = newNode(53);
	root->right->left  = newNode(23);
	root->right->left->right = newNode(37);
	root->right->left->right->left = newNode(29);
	root->right->left->right->right = newNode(41);
	root->right->left->right->left->right = newNode(31);

	int k = 5;
	vector<int> res;

	findKLargest(root, k, res);

	//print k largest
	for (auto itr = res.begin(); itr != res.end(); itr++) {
		cout << *itr << endl;
	}


	return 0;
}

