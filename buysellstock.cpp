#include <bits/stdc++.h>

using namespace std;

void buyAndSellStockOnceBF(int arr[], int n) {

	int max_val = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {

			max_val = max(max_val, arr[j] - arr[i]);
			//cout << max_val << endl;

		}
	}

	cout << max_val << endl;
}

void buyAndSellStockOnce(int arr[], int n) {

	int min_sofar = INT_MAX;
	int max_profit = 0;

	for (int i = 0; i < n; i++) {

		min_sofar = min(min_sofar, arr[i]);
		//if we subtract the minsofar with the present val, we can compare and get max profit
		max_profit = max(max_profit, arr[i] - min_sofar);

	}

	cout << max_profit << endl;

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

	buyAndSellStockOnceBF(arr, n);
	buyAndSellStockOnce(arr, n);

	return 0;
}




