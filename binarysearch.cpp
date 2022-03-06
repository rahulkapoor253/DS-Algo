#include <bits/stdc++.h>

using namespace std;

int binarySearchRecursive(int arr[], int start, int end, int key) {

	if (start <= end) {

		int mid = start + (end - start) / 2;//mid is calculated like this only to avoid overflow

		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			//key is ahead somewhere
			return binarySearchRecursive(arr, mid + 1, end, key);
		}

		return binarySearchRecursive(arr, start, mid - 1, key);
	}

//key not found
	return -1;
}

int binarySearchIterative(int arr[], int start, int end, int key) {

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			start = mid + 1;//ignore first half
		}
		else {
			end = mid - 1;//ignore last half
		}

	}

	return -1;//not able to find the key
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

	int ind1 = binarySearchRecursive(arr, 0, n - 1, key);
	cout << ind1 << endl;

	int ind2 = binarySearchIterative(arr, 0, n - 1, key);
	cout << ind1 << endl;

}