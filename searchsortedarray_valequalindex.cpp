#include <bits/stdc++.h>

using namespace std;

int computeSimilarValueOccurence(int arr[], int start, int end) {

	if (start <= end) {

		int mid = start + (end - start) / 2;

		if (arr[mid] == mid) {
			return mid;
		}
		//now duplicates are allowed so we cannot exlude any case
		int left_ind = computeSimilarValueOccurence(arr, start, mid - 1);

		if (left_ind >= 0) {
			return left_ind;
		}

		int right_ind = computeSimilarValueOccurence(arr, mid + 1, end);

		if (right_ind >= 0) {
			return right_ind;
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

//for duplicates allowed T = O(n) but in average cases we can make it to T = O(logn)
	cout << computeSimilarValueOccurence(arr, 0, n - 1);

}

