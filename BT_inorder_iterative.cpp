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

void computeInorderIterative(struct Node* root) {

	stack<Node*> st;
	struct Node* curr = root;

	while (!st.empty() || curr) {

		if (curr) {

			st.push(curr);
			curr = curr->left;

		}
		else {

			struct Node* temp = st.top();
			st.pop();
			cout << temp->data << " ";
			curr = temp->right;

		}

	}

}

void computePreorderIterative(struct Node* root) {

	stack<Node*>st;
	st.push(root);

	while (!st.empty()) {

		struct Node* curr = st.top();
		st.pop();

		if (curr) {

			cout << curr->data << " ";
			st.push(curr->right);
			st.push(curr->left);

		}

	}

}

void computePostorderIterative(struct Node* root) {

	//we take reverse post order in a stack and then print it
	stack<Node*> st1, st2;
	st1.push(root);

	while (!st1.empty()) {

		struct Node* curr = st1.top();
		st1.pop();
		st2.push(curr);

		if (curr->left) {
			st1.push(curr->left);
		}

		if (curr->right) {
			st1.push(curr->right);
		}

	}

	//now stack2 has reverse post order in it
	while (!st2.empty()) {

		Node* curr = st2.top();
		st2.pop();
		cout << curr->data << " ";

	}

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

	computeInorderIterative(root);
	cout << endl;
	computePreorderIterative(root);
	cout << endl;
	computePostorderIterative(root);

	return 0;
}
