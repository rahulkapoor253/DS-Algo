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

Node* computeAddition(Node* head1, Node* head2) {

	Node* head = NULL;

	Node* ptr1 = head1;
	Node* ptr2 = head2;
	int carry = 0;

	while (ptr1 != NULL && ptr2 != NULL) {
		//cout << carry << endl;

		int sum = ptr1->data + ptr2->data + carry;//as carry will start occuring if sum goes beyond 10

		if (sum > 9) {
			carry = sum / 10;
			sum = sum % 10;
		}
		else {
			carry = 0;
		}

		pushNode(head, sum);

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;

	}

	while (ptr1) {

		int sum = ptr1->data + carry;//as carry will start occuring if sum goes beyond 10

		if (sum > 9) {
			carry = sum / 10;
			sum = sum % 10;
		}
		else {
			carry = 0;
		}

		pushNode(head, sum);
		ptr1 = ptr1->next;
	}

	while (ptr2) {
		int sum = ptr2->data + carry;//as carry will start occuring if sum goes beyond 10

		if (sum > 9) {
			carry = sum / 10;
			sum = sum % 10;
		}
		else {
			carry = 0;
		}

		pushNode(head, sum);
		ptr2 = ptr2->next;
	}

	if (carry > 0) {
		pushNode(head, carry);
	}

	return head;
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

	int n1, n2;
	cin >> n1;
	cin >> n2;

	int val;
	Node* head1 = NULL;
	Node* head2 = NULL;

	for (int i = 0; i < n1; i++) {
		cin >> val;
		pushNode(head1, val);
	}

	for (int i = 0; i < n2; i++) {
		cin >> val;
		pushNode(head2, val);
	}

	Node* head3 = computeAddition(head1, head2);

	printList(head3);

	return 0;
}




