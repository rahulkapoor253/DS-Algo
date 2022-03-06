#include <bits/stdc++.h>

using namespace std;

int computeFirstOccurenceBS(int arr[], int start, int end, int key) {
	//cout << start << ":" << end << endl;

	if (start <= end) {

		int mid = start + (end - start) / 2;//to avoid overflow

		if (arr[mid] == key) {

			//check if it is the first occurence of the key or go backwards
			if (mid - 1 >= 0 && arr[mid - 1] == arr[mid]) {

				//binary search on the prev half to optimize linear backsearch
				return computeFirstOccurenceBS(arr, start, mid - 1, key);

			}
			else {
				return mid;
			}

		}
		else if (arr[mid] > key) {
			return computeFirstOccurenceBS(arr, start, mid - 1, key);
		}

		return computeFirstOccurenceBS(arr, mid + 1, end, key);
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

	cout << computeFirstOccurenceBS(arr, 0, n - 1, key);

}

