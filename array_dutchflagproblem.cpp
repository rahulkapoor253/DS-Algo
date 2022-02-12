#include <bits/stdc++.h>

using namespace std;

void pivoting(int arr[], int n, int pivot) {

//handling smaller elements to left
	int i = -1;
	int j = 0;
	for (j = 0; j < n; j++) {

		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}

	}

	//handling larger elements to right of pivot elements
	i = n;
	j = n - 1;
	//we put this >= pivot condition because all elements to left of pivot are already set to small
	for (j = n - 1; j >= 0 && arr[j] >= pivot; j--) {

		if (arr[j] > pivot) {
			i--;
			swap(arr[i], arr[j]);
		}

	}

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

	int pivot_ind;
	cin >> pivot_ind;
	int pivot = arr[pivot_ind];

	pivoting(arr, n, pivot);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}




