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

Node* computeSwapKNodes(Node* head, int k) {

	if (head == NULL) {
		return head;
	}

	Node* curr = head;
	Node* prev = NULL;
	Node* temp = NULL;
	int count = 0;//to count every k nodes

	//we can have exact k times swap or k-1 times whole swap and last partial swap
	while (curr != NULL && count < k) {

		//reverse Nodes logic
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;

		count++;

	}

	if (curr != NULL) {
		head->next = computeSwapKNodes(curr, k);
	}

	return prev;
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

	int k;
	cin >> k;

	head1 = computeSwapKNodes(head1, k);

	printList(head1);

	return 0;
}




