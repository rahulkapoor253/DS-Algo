#include <bits/stdc++.h>

using namespace std;

void computeBuildingsWithView(int arr[], int n) {

	int max_running = -1;

	for (int i = 0; i < n; i++) {

		if (arr[i] > max_running) {
			cout << i << endl;
			max_running = arr[i];
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

	computeBuildingsWithView(arr, n);

	return 0;
}
