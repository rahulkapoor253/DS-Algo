#include <bits/stdc++.h>

using namespace std;

class Stack {

private:
	struct StackMax {
		int element;
		int max_val;
	};
	stack<StackMax> st;

public:
	bool Empty() {
		return st.empty();
	}

	void MaxVal() {

		if (Empty()) {
			cout << "Stack is empty" << endl;
		}

		StackMax sm = st.top();
		cout << "Max Val: " << sm.max_val << endl;

	}

	int Pop() {

		if (Empty()) {
			return -1;
		}

		StackMax sm = st.top();
		st.pop();
		return sm.element;
	}

	void Push(int val) {

		int maxval = -1;

		if (Empty()) {
			maxval = val;
		}
		else {
			StackMax sm = st.top();
			maxval = max(val, sm.max_val);
		}

		st.push(StackMax{val, maxval});
	}

	void PrintStack() {

		while (!Empty()) {
			cout << Pop() << endl;
		}

	}

};

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	// Stack s;

	// s.Push(10);
	// s.MaxVal();

	// s.Push(20);
	// s.MaxVal();

	// s.Push(5);
	// s.MaxVal();

	// s.Push(13);
	// s.MaxVal();

	// s.Push(1);
	// s.MaxVal();

	// s.Push(45);
	// s.MaxVal();

	// s.PrintStack();


	return 0;
}
