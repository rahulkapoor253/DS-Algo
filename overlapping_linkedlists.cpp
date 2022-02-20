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

Node* computeOverlappingLLCycle(Node* head1, Node* head2, Node* root1, Node* root2) {

	Node* curr = NULL;
	int len1 = 0;
	int len2 = 0;

	curr = head1;
	while (curr != NULL && curr != root1) {
		curr = curr->next;
		len1++;
	}

	curr = head2;
	while (curr != NULL && curr != root2) {
		curr = curr->next;
		len2++;
	}

	//now we have distance of both lists to root1 and root2 which are their cycle starting points
	//we have 2 scenarios where cycle can start before overlapping point or after it
	int diff = 0;
	if (len1 > len2) {
		//advance head1 by diff
		diff = len1 - len2;
		while (diff > 0) {
			head1 = head1->next;
			diff--;
		}

	}
	else {
		//advance head2 by diff
		diff = len2 - len1;
		while (diff > 0) {
			head2 = head2->next;
			diff--;
		}

	}

	curr = head1;
	Node* curr1 = head2;

	while (curr != NULL && curr1 != NULL && curr != curr1 && curr != root1 && curr1 != root2) {
		curr = curr->next;
		curr1 = curr1->next;
	}

	if (curr == curr1) {
		return curr;
	}
	else {
		return root1;
	}
}

Node* computeOverlappingLL(Node* head1, Node* head2) {

	Node* curr = NULL;
	int len1 = 0;
	int len2 = 0;

	curr = head1;
	while (curr != NULL) {
		curr = curr->next;
		len1++;
	}

	curr = head2;
	while (curr != NULL) {
		curr = curr->next;
		len2++;
	}

	int diff = 0;
	//we have both lengths, they overlap from the very first node part till end of LinkedList
	if (len1 > len2) {
		//advance head1 by diff
		diff = len1 - len2;
		while (diff > 0) {
			head1 = head1->next;
			diff--;
		}

	}
	else {
		//advance head2 by diff
		diff = len2 - len1;
		while (diff > 0) {
			head2 = head2->next;
			diff--;
		}

	}

	curr = head1;
	Node* curr1 = head2;

	while (curr != NULL && curr1 != NULL) {

		if (curr == curr1) {
			return curr;
		}

		curr = curr->next;
		curr1 = curr1->next;
	}

	return NULL;
}

void printList(struct Node* head) {

	Node* ptr = head;

	while (ptr != NULL) {
		cout << ptr->data << endl;
		ptr = ptr->next;
	}

}

Node* checkCycle(Node* head) {

	//fast and slow pointer technique
	Node* slow = head;
	Node* fast = head;

	while (slow && fast && fast->next && fast->next->next) {

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {

			slow = head;
			while (slow && fast && slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}

			return slow;
		}

	}

	return NULL;
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

	//manually design LL2
	Node* head2 = NULL;
	int n2 = 6;
	pushNode(head2, 10);
	pushNode(head2, 20);
	head2->next->next = head1->next->next->next;
	//create a cycle
	head2->next->next->next->next->next->next = head2->next->next->next->next;

//overlapping with a cycle, it means both LinkedLists have cycles each
	//if 1 LL has cycle other not, no overlapping
	//if both LL dont have cycle, then normal overlapping problem

	Node* root1 = NULL;
	Node* root2 = NULL;
	Node* res = NULL;

	root1 = checkCycle(head1);
	root2 = checkCycle(head2);

	//cout << root1->data << ":" << root2->data << endl;

	if (root1 == NULL && root2 == NULL) {
		res = computeOverlappingLL(head1, head2);
		cout << "Overlap begins at: " << res->data << endl;
	}
	else if ( (root1 == NULL && root2 != NULL ) || (root1 != NULL && root2 == NULL) ) {
		cout << "No overlap present" << endl;
	}
	else {
		res = computeOverlappingLLCycle(head1, head2, root1, root2);
		cout << "Overlap begins at: " << res->data << endl;
	}

	//printList(head2);

	return 0;
}




