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

void removeDuplicates(Node* &head) {

	Node* ptr = head;

	while (ptr != NULL && ptr->next != NULL) {

		if (ptr->data == ptr->next->data) {

			Node* temp = ptr->next;
			ptr->next = temp->next;
			free(temp);

		}

		ptr = ptr->next;
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

	removeDuplicates(head1);

	printList(head1);

	return 0;
}




