#include <bits/stdc++.h>

using namespace std;

bool advancingArrayGame(int arr[], int n) {

	int reach = 0;
	for (int i = 0; i < n && i <= reach; i++) {

		reach = max(reach, arr[i] + i);

	}

	if (reach >= n - 1) {
		return true;
	}

	return false;
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

	cout << advancingArrayGame(arr, n);

	return 0;
}




