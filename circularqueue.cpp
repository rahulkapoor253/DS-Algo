#include <bits/stdc++.h>

using namespace std;

class Queue {

private:
	int capacity;
	int front;
	int rear;
	int *arr;

public:
	Queue(int s)
	{
		front = rear = -1;
		capacity = s;
		arr = new int[s];
	}

	void enQueue(int val);
	int deQueue();
	void displayQueue();

};

void Queue::enQueue(int val) {

	if (rear == capacity - 1 && front == 0) {
		cout << "queue is full" << endl;
		return;
	}

	if (rear == ((front - 1) % (capacity - 1))) {
		cout << "queue is full" << endl;
		return;
	}

	if (front == -1 && rear == -1) {
		front = 0;
		rear = 0;
		arr[front] = val;
	}
	else if (rear == capacity - 1 && front != 0) {
		rear = 0;
		arr[rear] = val;
	}
	else {
		rear++;
		arr[rear] = val;
	}

}

int Queue::deQueue() {

	if (front == -1) {
		cout << "queue is empty" << endl;
		return -1;
	}

	int val = arr[front];
	arr[front] = -1;//to represent that this element has been removed

	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == capacity - 1) {
		front = 0;
	}
	else {
		front++;
	}

	return val;
}

void Queue::displayQueue() {

	if (front == -1) {
		cout << "Queue is empty" << endl;
		return;
	}

	if (rear >= front) {

		for (int i = front; i <= rear; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;
	}
	else {

		for (int i = front; i < capacity; i++) {
			cout << arr[i] << " ";
		}

		for (int i = 0; i <= rear; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;

	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	Queue q(5);

	// Inserting elements in Circular Queue
	q.enQueue(14);
	q.enQueue(22);
	q.enQueue(13);
	q.enQueue(-6);

	// Display elements present in Circular Queue
	q.displayQueue();

	// Deleting elements from Circular Queue
	printf("\nDeleted value = %d", q.deQueue());
	cout << endl;
	printf("\nDeleted value = %d", q.deQueue());
	cout << endl;

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);

	q.displayQueue();

	q.enQueue(20);

	return 0;
}
