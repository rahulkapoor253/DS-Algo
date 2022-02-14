#include <bits/stdc++.h>

using namespace std;

void computePascalTriangle(int n) {

	vector<vector<int>> arr(n);

	for (int i = 0; i < n; i++) {

		for (int j = 0; j <= i; j++) {

			if (j == 0 || j == i) {
				arr[i].push_back(1);
			}
			else {
				arr[i].push_back(arr[i - 1][j] + arr[i - 1][j - 1]);//sum of prev row same element and element before
			}

		}

	}

	for (int i = 0; i < n; i++) {
		for (auto itr = arr[i].begin(); itr != arr[i].end(); itr++) {
			cout << *itr << " ";
		}
		cout << endl;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	computePascalTriangle(n);

	return 0;
}




