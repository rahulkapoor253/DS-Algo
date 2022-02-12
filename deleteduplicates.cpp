#include <bits/stdc++.h>

using namespace std;

int deleteDuplicates(int arr[], int n) {

	int i = 1;
	int vacant = 1;//we can keep track of the duplicate and fill it with the next diff. value

	for (i = 1; i < n; i++) {

		if (arr[vacant - 1] != arr[i]) {
			arr[vacant] = arr[i];
			vacant++;
		}

	}

	return vacant;//which will act as the max size of array
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

	int max_size = deleteDuplicates(arr, n);

	for (int i = 0; i < max_size; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}




