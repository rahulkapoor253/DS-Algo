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

Node* computePivoting(Node* &head, int pivot) {
//pivoting will be node elements less than pivot -> pivot elements -> node elements greater than pivot
	Node* ptr1 = NULL;
	Node* ptr2 = NULL;
	Node* ptr3 = NULL;

	Node* ptr1_start = NULL;
	Node* ptr2_start = NULL;
	Node* ptr3_start = NULL;

	Node* curr = head;

	while (curr != NULL) {

		if (curr->data < pivot) {

			if (ptr1 == NULL) {
				ptr1 = curr;
				ptr1_start = curr;
			}
			else {
				ptr1->next = curr;
				ptr1 = curr;
			}

		}
		else if (curr->data > pivot) {

			if (ptr3 == NULL) {
				ptr3 = curr;
				ptr3_start = ptr3;
			}
			else {
				ptr3->next = curr;
				ptr3 = curr;
			}

		}
		else {

			if (ptr2 == NULL) {
				ptr2 = curr;
				ptr2_start = ptr2;
			}
			else {
				ptr2->next = curr;
				ptr2 = curr;
			}

		}

		curr = curr->next;
	}

	//bind all three considering empty cases

	if (ptr3 != NULL) {
		ptr3->next = NULL;
	}

	if (ptr1 == NULL) {

		if (ptr2 == NULL) {
			return ptr3_start;
		}

		ptr2->next = ptr3_start;
		return ptr1_start;
	}

	if (ptr2 == NULL) {
		ptr1->next = ptr3_start;
		return ptr1_start;
	}

	ptr1->next = ptr2_start;
	ptr2_start->next = ptr3_start;

	return ptr1_start;
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

	int n1;
	cin >> n1;

	int val;
	Node* head1 = NULL;

	for (int i = 0; i < n1; i++) {
		cin >> val;
		pushNode(head1, val);
	}

	int pivot;
	cin >> pivot;

	Node* head = computePivoting(head1, pivot);

	printList(head);

	return 0;
}
