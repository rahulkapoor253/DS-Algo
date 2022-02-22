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

bool computePalindromeBF(Node* head) {

	if (head == NULL || head->next == NULL) {
		return true;
	}

	Node* head1 = NULL;
	Node* ptr = head;

	while (ptr != NULL) {

		Node* new_node = new Node();
		new_node->data = ptr->data;
		new_node->next = head1;
		head1 = new_node;

		ptr = ptr->next;
	}

//so head1 becomes a new LinkedList which is reverse of existing LL

	ptr = head;
	Node* ptr1 = head1;

	while (ptr != NULL && ptr1 != NULL) {

		if (ptr->data != ptr1->data) {
			return false;
		}

		ptr = ptr->next;
		ptr1 = ptr1->next;

	}

	if (ptr == NULL && ptr1 == NULL) {
		return true;
	}

	return false;
}

bool computePalindromeOptimized(Node* head) {

	if (head == NULL || head->next == NULL) {
		return true;
	}

	//we can reverse the 2nd half of LinkedList and then check for palindrome
	Node* slow = head;
	Node* fast  = head;

	while (slow != NULL && fast != NULL && fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	Node* curr = slow;
	Node* prev = NULL;
	// fast == NULL, even list and reverse it from slow
	//fast != NULL, odd list and reverse it from slow->next
	if (fast != NULL) {
		curr = slow->next;
	}
	//reverse the list from slow onwards till tail of Linkedlist

	while (curr != NULL) {

		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;

	}

	slow->next = prev;

	Node* ptr1 = head;
	Node* ptr2 = slow->next;

	while (ptr1 != NULL && ptr2 != NULL) {

		if (ptr1->data != ptr2->data) {
			return false;
		}

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;

	}

	return true;
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

	cout << computePalindromeBF(head1) << endl;

	cout << computePalindromeOptimized(head1) << endl;

	return 0;
}




