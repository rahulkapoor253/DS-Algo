#include <bits/stdc++.h>

using namespace std;

struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(char val) {

	struct Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

int searchNodeIndex(char in[], int start, int end, char val) {

	int i = start;

	for (i = start; i <= end; i++) {

		if (in[i] == val) {
			return i;
		}

	}

	return -1;
}

struct Node* buildTree(char in[], char pre[], int start, int end) {

	static int preInd = 0;

	if (start > end) {
		return NULL;
	}

	struct Node* new_node = newNode(pre[preInd]);
	preInd++;

//if no further children
	if (start == end) {
		return new_node;
	}

	//search this new_node in inorder array, so we can divide the LST and RST
	int inInd = searchNodeIndex(in, start, end, new_node->data);

	new_node->left = buildTree(in, pre, start, inInd - 1);
	new_node->right = buildTree(in, pre, inInd + 1, end);

	return new_node;
}

void printInorder(struct Node* root) {

	if (root == NULL) {
		return;
	}

	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	int len = sizeof(in) / sizeof(in[0]);
	Node* root = buildTree(in, pre, 0, len - 1);

	/* Let us test the built tree by
	printing Inorder traversal */
	cout << "Inorder traversal of the constructed tree is \n";
	printInorder(root);

	return 0;
}
