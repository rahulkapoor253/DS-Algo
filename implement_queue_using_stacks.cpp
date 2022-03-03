#include <bits/stdc++.h>

using namespace std;

class Queue {

private:
	stack<int> st1, st2;

public:
	void enQueue(int val);
	int deQueue();

};

void Queue::enQueue(int val) {
	st1.push(val);
}

int Queue::deQueue() {

	//transfer all elements from st1 to st2
	while (!st1.empty()) {

		st2.push(st1.top());
		st1.pop();

	}

	if (!st2.empty()) {
		int val = st2.top();
		st2.pop();

		return val;
	}

	return -1;
}


int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';

	return 0;
}
