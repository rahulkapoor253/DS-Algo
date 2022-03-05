#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
};

struct Node* newNode(int val) {

	struct Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;

	return temp;
}

void inorderSuccessor(struct Node* root, struct Node* val) {

	//if node has a right subtree
	if (val->right != NULL) {

		struct Node* curr = val->right;
		while (curr->left != NULL) {

			curr = curr->left;

		}

		cout << curr->data << endl;

		return;
	}

	if (val->right == NULL) {

		//either inorder succ lies in its above parent, or its the rightmost node of BT
		struct Node* curr = root;
		while (curr->right != NULL) {
			curr = curr->right;
		}

		if (curr == val) {
			cout << -1 << endl;
			return;
		}

		//inorder successor lies in its parent node
		while (val->parent != NULL && val->parent->right == val) {
			val = val->parent;
		}

		cout << val->parent->data << endl;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Node* root = newNode(1);
	root->left = newNode(2);
	root->left->parent = root;

	root->right = newNode(3);
	root->right->parent = root;

	root->left->left = newNode(4);
	root->left->left->parent = root->left;

	root->left->right = newNode(5);
	root->left->right->parent = root->left;

	root->right->left = newNode(6);
	root->right->left->parent = root->right;

	root->right->right = newNode(7);
	root->right->right->parent = root->right;

	// Case 1 : When there is a right child
	// eg: Node(1) has a right child ergo the inorder successor would be leftmost
	// node of the right subtree ie 6.
	inorderSuccessor(root, root);

	// case 2: When the right child is NULL
	// eg: From the above figure Node(5) satisfies this case
	inorderSuccessor(root, root->left->left);

	inorderSuccessor(root, root->left->right);

	// case 3: When the node is the rightmost node of the binary tree
	inorderSuccessor(root, root->right->right);

	return 0;
}
