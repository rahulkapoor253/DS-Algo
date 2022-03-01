#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

struct QueueNode {
	Node* my_node;
	int depth;
};

void computeNodesBasedOnDepth(struct Node* root) {

	queue<QueueNode> q;
	vector<vector<int>> res(10);

	q.push({root, 0});//start depth with 0

	while (!q.empty()) {

		QueueNode temp = q.front();
		q.pop();

		res[temp.depth].push_back(temp.my_node->data);

		if (temp.my_node->left != NULL) {
			q.push({temp.my_node->left, temp.depth + 1});
		}

		if (temp.my_node->right != NULL) {
			q.push({temp.my_node->right, temp.depth + 1});
		}

	}

	int size = res.size();

	for (int i = 0; i < size; i++) {
		for (auto itr = res[i].begin(); itr != res[i].end(); itr++) {

			cout << *itr << " ";

		}
		cout << endl;
	}

}

struct Node* newNode(int val) {

	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	computeNodesBasedOnDepth(root);

	return 0;
}
