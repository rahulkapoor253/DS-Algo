#include <bits/stdc++.h>

using namespace std;

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int m, n;
	cin >> m;
	cin >> n;

	int key;
	cin >> key;

	int arr[m][n];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	bool isFound = false;
	//compute 2d search
	if (key < arr[0][0]) {
		isFound = false;
	}
	else {

		int row = 0;
		int col = n - 1;

		while (row < m && col >= 0) {

			if (key == arr[row][col]) {
				isFound = true;
				break;
			}
			else if (key < arr[row][col]) {
				//last column will be discarded
				col--;
			}
			else {
				//current row can be discarded
				row++;
			}

		}

	}

	cout << isFound << endl;

}

