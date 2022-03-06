#include <bits/stdc++.h>

using namespace std;

int searchMinCyclicSorted(int arr[], int start, int end) {

	while (start < end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] < arr[end]) {
			//later part will have data in increasing order
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return start;
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

	cout << searchMinCyclicSorted(arr, 0, n - 1);

}

