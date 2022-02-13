#include <bits/stdc++.h>

using namespace std;

void buyAndSellStockTwice(int arr[], int n) {

	int profit1[n];
	int profit2[n];

	for (int i = 0; i < n; i++) {
		profit1[i] = 0;
		profit2[i] = 0;
	}

	int min_sofar = INT_MAX;
	int max_sofar = 0;

	for (int i = 0; i < n; i++) {

		min_sofar = min(min_sofar, arr[i]);
		max_sofar = max(max_sofar, arr[i] - min_sofar);
		profit1[i] = max_sofar;
		//cout << max_sofar << " ";

	}

	//cout << endl;

	int max_val = 0;
	max_sofar = 0;

	for (int i = n - 1; i >= 0; i--) {

		max_val = max(max_val, arr[i]);
		max_sofar = max(max_sofar, max_val - arr[i]);
		profit2[i] = max_sofar;
		//cout << max_sofar << " ";
	}

	int max_profit = 0;
	for (int i = 0; i < n - 1; i++) {
		max_profit = max(max_profit, profit1[i] + profit2[i + 1]);
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

	buyAndSellStockTwice(arr, n);

	return 0;
}




