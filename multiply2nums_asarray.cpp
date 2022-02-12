#include <bits/stdc++.h>

using namespace std;

void multiplyLargeNums(int arr1[], int arr2[], int n1, int n2) {

	bool sign = false;
	if (arr1[0] < 0 && arr2[0] > 0) {
		sign = true;
	}

	if (arr1[0] > 0 && arr2[0] < 0) {
		sign = true;
	}

	int res[n1 + n2];
	for (int i = 0; i < n1 + n2; i++) {
		res[i] = 0;
	}

	//multiply each num using nested loop and add all the results
	for (int i = n1 - 1; i >= 0; i--) {
		for (int j = n2 - 1; j >= 0; j--) {
//rather than storing all results separately and adding them up, add here itself
			res[i + j + 1] += abs(arr1[i]) * abs(arr2[j]);
			res[i + j] += res[i + j + 1] / 10;
			res[i + j + 1] = res[i + j + 1] % 10;

		}
	}

	if (sign) {
		res[0] = -res[0];
	}

	for (int i = 0; i < n1 + n2; i++) {
		cout << res[i];
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n1, n2;

	cin >> n1;
	cin >> n2;

	int arr1[n1];
	int arr2[n2];

	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}

	multiplyLargeNums(arr1, arr2, n1, n2);

	return 0;
}




