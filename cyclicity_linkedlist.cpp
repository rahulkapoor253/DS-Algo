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

void computeCyclicity(Node* head) {

	Node* ptr = head;
	unordered_map<Node*, int> umap;

	while (ptr != NULL) {

		if (umap.find(ptr) == umap.end()) {
			//not present already
			umap[ptr]++;
		}
		else {
			//already present in umap
			cout << "Present: " << ptr->data << endl;
			return;
		}

		ptr = ptr->next;
	}

	cout << "Not Present" << endl;
}

void computeCyclicityFastSlow(Node* head) {

	Node* slow = head;
	Node* fast = head;

	while (slow && fast && fast->next && fast->next->next) {

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			//they meet up at some point, hence cycle is present
			//head->steps till start of cycle will be from meeting point->same steps
			slow = head;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}

			cout << "Present fast and slow at: " << slow->data << endl;
			return;

		}

	}

	cout << "Not Present" << endl;

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

//manually creating a cycle
	Node* ptr = head1;
	while (ptr->next) {
		ptr = ptr->next;
	}

	ptr->next = head1->next->next;

	computeCyclicity(head1);
	cout << endl;
	computeCyclicityFastSlow(head1);

//	printList(head1);

	return 0;
}




