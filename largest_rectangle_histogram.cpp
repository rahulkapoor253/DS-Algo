#include <bits/stdc++.h>

using namespace std;

int computeLargestRectangle(int arr[], int n) {

//previous smaller element
//next smaller element

	int pse[n];
	int nse[n];
	int area[n];

	stack<int> st;
	stack<int> st1;

	pse[0] = -1;
	st.push(0);

	for (int i = 1; i < n; i++) {

		while (!st.empty() && arr[st.top()] >= arr[i]) {
			st.pop();
		}

		if (st.empty()) {
			pse[i] = -1;
		}
		else {
			pse[i] = st.top();
		}

		st.push(i);

	}

	nse[n - 1] = -1;
	st1.push(n - 1);

	for (int i = n - 2; i >= 0; i--) {

		while (!st1.empty() && arr[st1.top()] >= arr[i]) {
			st1.pop();
		}

		if (st1.empty()) {
			nse[i] = -1;
		}
		else {
			nse[i] = st1.top();
		}

		st1.push(i);

	}

	int res = 0;
	int left = -1;
	int right = -1;

	for (int i = 0; i < n; i++) {
		cout << pse[i] << ":" << nse[i] << endl;
	}

	for (int i = 0; i < n; i++) {

		if (pse[i] == -1) {
			left = i;
		}
		else {
			left = i - pse[i] - 1;
		}

		if (nse[i] == -1) {
			right = n - 1 - i;
		}
		else {
			right = nse[i] - i - 1;
		}

		res = max(res, (left + right + 1) * arr[i]);

	}

	return res;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//Brute Force done at hackerrank:
	//	https://www.hackerrank.com/challenges/largest-rectangle/problem

	cout << computeLargestRectangle(arr, n) << endl;

	return 0;
}
