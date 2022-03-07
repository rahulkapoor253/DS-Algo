#include <bits/stdc++.h>

using namespace std;

int computeKthlargestBruteForce(int arr[], int n, int key) {
//T = O(nlogn)
	sort(arr + 0, arr + n);

	return arr[n - key];
}

int computePivoting(int arr[], int left, int right, int pivot_index) {

	int i = left;
	int j = left;

	for (i = left; i < right; i++) {

		if (arr[i] <= arr[pivot_index]) {
			swap(arr[i], arr[j]);
			j++;
		}

	}

	//swap both j and pivot_index
	swap(arr[j], arr[pivot_index]);

	return j;
}

int computeKthlargestQuickSelect(int arr[], int n, int key) {

	//this works based on pivoting and discarding half each time
	//Tavg = O(n) but worst-case T = O(n^2)
	int left = 0;
	int right = n - 1;

	while (left <= right) {

		int pivot_index = right;
		int new_pivot_index = computePivoting(arr, left, right, pivot_index);

		cout << "pivot_index: " << new_pivot_index << endl;
//as all elements to the right of new_pivot_index are greater than it, irrespective of its sorting
		if (n - key == new_pivot_index) {
			return arr[new_pivot_index];
		}
		else if (n - key > new_pivot_index) {
			left = new_pivot_index + 1;
		}
		else {
			right = new_pivot_index - 1;
		}

	}

	return -1;
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

	int key;
	cin >> key;

	cout << computeKthlargestBruteForce(arr, n, key);
	cout << endl;
	cout << computeKthlargestQuickSelect(arr, n, key);

}

