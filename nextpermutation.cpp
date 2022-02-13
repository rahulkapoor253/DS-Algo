#include <bits/stdc++.h>

using namespace std;

void computeNextPermutation(int arr[], int n) {
	//next_permutation(arr, arr + n);

	//approached from right to know the smallest and largest elements to be swapped
	int i = n - 1;
	bool isExit = false;

	while (i >= 0) {

		//move till its in descending
		if (i == n - 1) {
			i--;
		}
		else if (arr[i] > arr[i + 1]) {
			i--;
		}
		else if (arr[i] < arr[i + 1]) {
			//swap with the nge in forward subarray
			for (int k = n - 1; k > i; k--) {
				//we traverse in reverse so tht the first greater elements comes up is the desired nge
				if (arr[k] > arr[i]) {
					swap(arr[k], arr[i]);
					isExit = 1;
					break;
				}
			}

		}

		if (isExit) {
			break;
		}
		else {
			i--;
		}

	}

	reverse(arr + i + 1, arr + n);

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

	computeNextPermutation(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}




