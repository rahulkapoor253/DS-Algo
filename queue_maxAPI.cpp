#include <bits/stdc++.h>

using namespace std;

class Queue {

private:
	queue<int> q_enq;
	deque<int> q_deq;

public:
	void enQueue(int val);
	int deQueue();
	void maxAPI();

};

void Queue::maxAPI() {
	cout << "Max element: " << q_deq.front() << endl;
}

//this maintains maximum element in the front of deque and next max. and so on...
void Queue::enQueue(int val) {

	q_enq.push(val);

	while (!q_deq.empty()) {

		if (q_deq.back() >= val) {
			break;
		}

		q_deq.pop_back();

	}

	q_deq.push_back(val);

}

int Queue::deQueue() {

	int val = q_enq.front();
	q_enq.pop();

	if (val == q_deq.front()) {
		q_deq.pop_front();
	}

	return val;
}


int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Queue q;
	q.enQueue(3);
	q.maxAPI();
	q.enQueue(5);
	q.maxAPI();
	q.enQueue(2);
	q.maxAPI();
	q.enQueue(4);
	q.maxAPI();
	cout << "Deq: " << q.deQueue() << endl;
	q.maxAPI();
	q.enQueue(1);
	q.maxAPI();
	cout << "Deq: " << q.deQueue() << endl;
	q.maxAPI();
	cout << "Deq: " << q.deQueue() << endl;
	q.maxAPI();
	cout << "Deq: " << q.deQueue() << endl;
	q.maxAPI();

	return 0;
}
