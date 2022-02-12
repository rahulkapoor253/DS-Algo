#include <bits/stdc++.h>

using namespace std;

void reorderEven(int arr[], int n) {

	int start = 0;
	int end = n - 1;

	while (start < end) {

		if (arr[start] % 2 == 0) {
			start++;//already in-place
		}
		else {
			swap(arr[start], arr[end]);
			end--;
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

	reorderEven(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}




