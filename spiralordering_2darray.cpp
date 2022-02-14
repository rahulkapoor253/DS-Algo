#include <bits/stdc++.h>

using namespace std;


int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int arr[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//logic
	vector<int> res;
	//traverse 1st row, last col, last row in reverse, first col in reverse
	int offset = 0;

	while (offset < n) {

		for (int i = offset; i < n - offset - 1; i++) {
			res.push_back(arr[offset][i]);
		}

		for (int i = offset; i < n - offset - 1; i++) {
			res.push_back(arr[i][n - offset - 1]);
		}

		for (int i = n - offset - 1; i > offset; i--) {
			res.push_back(arr[n - offset - 1][i]);
		}

		for (int i = n - offset - 1; i > offset; i--) {
			res.push_back(arr[i][offset]);
		}

		offset++;
	}

	//if we have odd dimension then the centre most element is left out
	if (n % 2 > 0) {
		res.push_back(arr[n / 2][n / 2]);
	}

	for (auto itr = res.begin(); itr != res.end(); itr++) {
		cout << *itr << endl;
	}

	return 0;
}




