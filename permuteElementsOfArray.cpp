#include <bits/stdc++.h>

using namespace std;

void permuteToArrayBF(int perm[], char arr[], int n) {

	char res[n];

	for (int i = 0; i < n; i++) {
		res[perm[i]] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << endl;
	}

}

void permuteToArray(int perm[], char arr[], int n) {

	for (int i = 0; i < n; i++) {

		int next = i;
		while (perm[next] >= 0) {

			swap(arr[i], arr[perm[next]]);
			int val = perm[next];
			perm[next] = perm[next] - n;
			next = val;

		}

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	char arr[n];
	int perm[n];

	for (int i = 0; i < n; i++) {
		cin >> perm[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//permuteToArrayBF(perm, arr, n);
	permuteToArray(perm, arr, n);

	return 0;
}




