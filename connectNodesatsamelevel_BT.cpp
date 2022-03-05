#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* nextRight;
};

struct Node* newNode(int val) {

	struct Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	temp->nextRight = NULL;

	return temp;
}

void connect(struct Node* root) {

	if (root == NULL) {
		return;
	}

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	//null marks end of the current level
	while (!q.empty()) {

		struct Node* temp = q.front();
		q.pop();

		if (temp != NULL) {

			temp->nextRight = q.front();

			if (temp->left) {
				q.push(temp->left);
			}

			if (temp->right) {
				q.push(temp->right);
			}

		}
		//put empty queue check to skip for the last level NULL
		else if (!q.empty()) {
			q.push(NULL);
		}

	}

}

struct Node* getNextRightNode(struct Node* root) {

	struct Node* temp = root->nextRight;

	while (temp != NULL) {

		if (temp->left) {
			return temp->left;
		}

		if (temp->right) {
			return temp->right;
		}

		temp = temp->nextRight;
	}

//for leaf nodes
	return NULL;
}

void connectOptimized(struct Node* root) {

//base case
	if (root == NULL) {
		return;
	}

	//before connecting this left node nextright, make sure right part of tree are connected
	//as they can be only reached from here
	if (root->nextRight != NULL) {
		connectOptimized(root->nextRight);
	}

	if (root->left) {

		if (root->right) {
			root->left->nextRight = root->right;
			//this will fetch Node from other side of the tree
			root->right->nextRight = getNextRightNode(root);
		}
		else {
			//connect root->left nextright to the node from other side of BT
			root->left->nextRight = getNextRightNode(root);
		}

		connectOptimized(root->left);
	}
	else if (root->right) {

		//connect it with node from other side of BT
		root->right->nextRight = getNextRightNode(root);
		connectOptimized(root->right);

	}
	else {
		connectOptimized(getNextRightNode(root));
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	struct Node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->right->right = newNode(90);

	// Populates nextRight pointer in all nodes
	//connect(root);
	connectOptimized(root);

	// Let us check the values of nextRight pointers
	printf("Following are populated nextRight pointers in \n"
	       "the tree (-1 is printed if there is no nextRight) \n");
	printf("nextRight of %d is %d \n", root->data,
	       root->nextRight ? root->nextRight->data : -1);
	printf("nextRight of %d is %d \n", root->left->data,
	       root->left->nextRight ? root->left->nextRight->data : -1);
	printf("nextRight of %d is %d \n", root->right->data,
	       root->right->nextRight ? root->right->nextRight->data : -1);
	printf("nextRight of %d is %d \n", root->left->left->data,
	       root->left->left->nextRight ? root->left->left->nextRight->data : -1);
	printf("nextRight of %d is %d \n", root->right->right->data,
	       root->right->right->nextRight ? root->right->right->nextRight->data : -1);

	return 0;
}
