#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void pushNode(struct Node* &head, int val) {

	//push to front as nodes are pushed in reverse
	Node* new_node = new Node();
	new_node->data = val;
	new_node->next = head;
	head = new_node;

}

void computeMerging(Node* head1, Node* head2, Node* &head3) {

	Node* ptr1 = head1;
	Node* ptr2 = head2;
	Node* ptr3 = head3;

	//edge cases
	if (ptr1 == NULL && ptr2 == NULL) {
		return;
	}

	if (ptr1 == NULL) {
		head3 = ptr2;
		return;
	}

	if (ptr2 == NULL) {
		head3 = ptr1;
		return;
	}

	while (ptr1 != NULL && ptr2 != NULL) {

		Node* new_node = new Node();
		new_node->next = NULL;

		if (ptr1->data <= ptr2->data) {
			new_node->data = ptr1->data;

			if (ptr3 == NULL) {
				ptr3 = new_node;
				head3 = new_node;
			}
			else {
				ptr3->next = new_node;
				ptr3 = ptr3->next;
			}

			ptr1 = ptr1->next;
		}
		else {
			new_node->data = ptr2->data;

			if (ptr3 == NULL) {
				ptr3 = new_node;
				head3 = new_node;
			}
			else {
				ptr3->next = new_node;
				ptr3 = ptr3->next;
			}

			ptr2 = ptr2->next;
		}

	}

	if (ptr1 == NULL && ptr2 != NULL) {
		//traverse the remaining ptr2
		ptr3->next = ptr2;
	}

	if (ptr2 == NULL && ptr1 != NULL) {
		//traverse remaining ptr1
		ptr3->next = ptr1;
	}

}

void printList(struct Node* head) {

	Node* ptr = head;

	while (ptr != NULL) {
		cout << ptr->data << endl;
		ptr = ptr->next;
	}

}

struct Node* computeMergingInPlace(Node* head1, Node* head2) {

	Node* ptr1 = head1;
	Node* ptr2 = head2;
	Node* ptr3 = NULL;
	struct Node* temp = NULL;
	struct Node* head = NULL;

	//edge cases
	if (ptr1 == NULL && ptr2 == NULL) {
		return ptr3;
	}

	if (ptr1 == NULL) {
		return head2;
	}

	if (ptr2 == NULL) {
		return head1;
	}

	while (ptr1 != NULL && ptr2 != NULL) {

		if (ptr1->data <= ptr2->data) {

			if (ptr3 == NULL) {
				head = ptr1;
				ptr3 = head;
				ptr1 = ptr1->next;
			}
			else {
				temp = ptr1;
				ptr1 = ptr1->next;
				ptr3->next = temp;
				ptr3 = ptr3->next;
			}

		}
		else {

			if (ptr3 == NULL) {
				head = ptr2;
				ptr3 = head;
				ptr2 = ptr2->next;
			}
			else {
				temp = ptr2;
				ptr2 = ptr2->next;
				ptr3->next = temp;
				ptr3 = ptr3->next;
			}

		}

	}

	if (ptr1 == NULL && ptr2 != NULL) {
		//traverse the remaining ptr2
		ptr3->next = ptr2;
	}

	if (ptr2 == NULL && ptr1 != NULL) {
		//traverse remaining ptr1
		ptr3->next = ptr1;
	}

	return head;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n1, n2;
	cin >> n1;
	cin >> n2;

	int val;
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* head3 = NULL;

	for (int i = 0; i < n1; i++) {
		cin >> val;
		pushNode(head1, val);
	}

	for (int i = 0; i < n2; i++) {
		cin >> val;
		pushNode(head2, val);
	}

	computeMerging(head1, head2, head3);

	cout << "printing list:" << endl;
	printList(head3);

	cout << endl;
	cout << "printing list in-place:" << endl;
	Node* temp = computeMergingInPlace(head1, head2);

	printList(temp);

	return 0;
}




