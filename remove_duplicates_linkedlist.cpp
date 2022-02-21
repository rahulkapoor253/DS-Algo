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

void oddEvenList(Node* &head) {

	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return;
	}

	//our list can be odd or even length.
	Node* curr_even = head->next;
	Node* curr_odd = head;

	//track first even as well
	Node* first_even = curr_even;

	while (1) {

		if (curr_even != NULL && curr_odd != NULL && curr_even->next == NULL) {
			curr_odd->next = first_even;
			break;
		}

		curr_odd->next = curr_even->next;
		curr_odd = curr_even->next;

//it has to be handled first, as odd may reach the end node in case of odd length list
		if (curr_even != NULL && curr_odd != NULL && curr_odd->next == NULL) {
			curr_even->next = NULL;
			curr_odd->next = first_even;
			break;
		}

		curr_even->next = curr_odd->next;
		curr_even = curr_odd->next;

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

	oddEvenList(head1);

	printList(head1);

	return 0;
}




