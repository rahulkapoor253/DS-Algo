#include <bits/stdc++.h>

using namespace std;

bool isDuplicatesPresent(vector<vector<int>> &arr, int row_start, int row_end, int col_start, int col_end) {

	vector<bool> isPresent(arr.size() + 1, false);

	for (int i = row_start; i < row_end; i++) {
		for (int j = col_start; j < col_end; j++) {

			if (arr[i][j] != 0 && isPresent[arr[i][j]]) {
				return true;
			}
			else {
				isPresent[arr[i][j]] = true;
			}
			//cout << isPresent[arr[i][j]] << endl;

		}
	}

	return false;
}

bool checkSudokuValid(vector<vector<int>> &arr, int n) {

	//verify row
	for (int i = 0; i < n; i++) {
		//take all columns for i'th row
		if (isDuplicatesPresent(arr, i, i + 1, 0, n)) {
			return false;
		}
	}

	//vrify column
	for (int i = 0; i < n; i++) {
		//take all rows for i'th column
		if (isDuplicatesPresent(arr, 0, n, i, i + 1)) {
			return false;
		}
	}

	//verify 3*3 sub-section
	int region_size = n / 3;

	for (int i = 0; i < region_size; i++) {
		for (int j = 0; j < region_size; j++) {

			if (isDuplicatesPresent(arr, i * region_size, (i + 1) * region_size,
			                        j * region_size, (j + 1) * region_size)) {
				return false;
			}

		}
	}

	return true;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n = 9;
	vector<vector<int>> arr(n);//defining 2d vector
	int val;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> val;
			arr[i].push_back(val);
		}
	}

	if (checkSudokuValid(arr, n)) {
		cout << "Valid" << endl;
	}
	else {
		cout << "Not valid" << endl;
	}

	return 0;
}




