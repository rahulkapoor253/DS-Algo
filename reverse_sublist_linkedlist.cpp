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

Node* computeReverseSublist(Node* &head, int x1 , int x2) {

	//traverse and save both nodes found
	Node* ptr1 = NULL;
	Node* ptr2 = NULL;
	Node* save1 = NULL;
	Node* save2 = NULL;

	Node* ptr = head;

	while (ptr != NULL) {

		if (ptr->data == x1) {
			ptr1 = ptr;
		}

		if (ptr->data == x2) {
			ptr2 = ptr;
			save2 = ptr2->next;
		}

		if (ptr1 == NULL) {
			save1 = ptr;
		}
		ptr = ptr->next;

	}

	//cout << ptr1->data << ":" << ptr2->data << endl;

	//reverse sublist from ptr1 till ptr2
	Node* curr = ptr1;
	Node* prev = NULL;

	while (curr != ptr2) {

		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;

	}

	curr->next = prev;//to join the last nodes of reversal
	// //join back the list Nodes

	if (ptr1 == head) {
		ptr1->next = save2;
		return curr;
	}

	if (save1 != NULL) {
		save1->next = curr;
	}

	ptr1->next = save2;

	return head;
}

void printList(struct Node* head) {

	Node* ptr = head;

	while (ptr != NULL) {
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

	int x1, x2;
	cin >> x1;
	cin >> x2;

	head1 = computeReverseSublist(head1, x1, x2);

	printList(head1);

	return 0;
}




