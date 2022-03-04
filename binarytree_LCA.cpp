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

bool computeLCAPath(struct Node* root, vector<int> &vec, int key) {

	if (root == NULL) {
		return false;
	}

	vec.push_back(root->data);

	if (root->data == key) {
		return true;
	}

	//from which subtree the data comes up
	if ( (root->left && computeLCAPath(root->left, vec, key))
	        || (root->right && computeLCAPath(root->right, vec, key)) ) {

		return true;

	}

	vec.pop_back();//remove nodes what were added in recursive calls but key wasn't found
	return false;
}

int findLCA(struct Node* root, int key1, int key2) {

	vector<int> vec1;
	vector<int> vec2;

	//we will be traversing both keys key1, key2 from root and pushing path into vec1, vec2
	bool found1 = computeLCAPath(root, vec1, key1);
	bool found2 = computeLCAPath(root, vec2, key2);

//either key is nowhere to be found in the whole BT
	if (found1 == false || found2 == false) {
		return -1;
	}

//compare both the vectors now
	int i = 0;
	int n1 = vec1.size();
	int n2 = vec2.size();

	for (i = 0; i < n1 && i < n2; i++) {

		if (vec1[i] != vec2[i]) {
			break;
		}

	}

	return vec1[i - 1];
}

int findLCAOptimized(struct Node* root, int key1, int key2) {

	if (root == NULL) {
		return -1;
	}

//if either of keys matches with this root then return it
	if (root->data == key1 || root->data == key2) {
		return root->data;
	}

	int left_val = findLCAOptimized(root->left, key1, key2);
	int right_val = findLCAOptimized(root->right, key1, key2);

	//cout << root->data << "->" << left_val << ":" << right_val << endl;
//both keys are on different subtrees of this root
	if (left_val != -1 && right_val != -1) {
		return root->data;
	}

//keys are on same subtree
	if (left_val != -1) {
		return left_val;
	}
	else {
		return right_val;
	}
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
	cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
	cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
	cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);

	cout << endl << endl;

	cout << "LCA(4, 5) = " << findLCAOptimized(root, 4, 5);
	cout << "\nLCA(4, 6) = " << findLCAOptimized(root, 4, 6);
	cout << "\nLCA(3, 4) = " << findLCAOptimized(root, 3, 4);
	cout << "\nLCA(2, 4) = " << findLCAOptimized(root, 2, 4);

	return 0;
}
