#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void pushNode(struct Node* &head, int val) {

	Node* new_node = new Node();
	new_node->data = val;
	new_node->next = NULL;

	if (head == NULL) {
		head = new_node;
	}
	else {

		Node* ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new_node;

	}

}

void removeKthNodeFromEndBF(Node* &head, int k) {

	//find the length of the LinkedList, then traverse from Length - k node to get the node to be deleted
	int len = 0;
	Node* ptr = head;

	while (ptr != NULL) {
		len++;
		ptr = ptr->next;
	}

	//cout << len << endl;
	int diff = len - k - 1;//this will be K + 1 th node from the end.
	ptr = head;

	while (diff > 0) {
		ptr = ptr->next;
		diff--;
	}

	Node* temp = ptr->next;
	ptr->next = temp->next;
	delete temp;

}

void removeKthNodeFromEndOptimized(Node* &head, int k) {

	//take 2 iterators and put one at pos. K
	//so others will move automatically for (n - k) till the ahead iterator reaches end
	Node* curr = head;
	Node* prev = head;

	while (k > 0 && curr != NULL) {
		curr = curr->next;
		k--;
	}

	if (curr == NULL) {
		//k is greater than or equal to 5
		head = head->next;
	}
	else {
		Node* save = NULL;
		//curr will be at k - 1 times from the end
		while (curr != NULL && prev != NULL) {
			curr = curr->next;
			save = prev;
			prev = prev->next;
		}

		save->next = prev->next;
		free(prev);
	}

}

void printList(Node* head) {

	Node* ptr = head;

	while (ptr) {
		cout << ptr->data << endl;
		ptr = ptr->next;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int val;
	Node* head1 = NULL;

	for (int i = 0; i < n; i++) {
		cin >> val;
		pushNode(head1, val);
	}

	int k;
	cin >> k;

	//removeKthNodeFromEndBF(head1, k);
	removeKthNodeFromEndOptimized(head1, k);

	printList(head1);

	return 0;
}




