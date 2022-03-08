#include <bits/stdc++.h>

using namespace std;

void computeMissingDuplicateElement(int arr[], int n) {

//0 to n is given
	int sum_total = 0;
	int sum_arr = 0;

	for (int i = 0; i < n; i++) {

		sum_total += i;
		sum_arr += arr[i];

	}

	int missing;
	int duplicate;
	//subtracting both will give missing - duplicate element equation, rest gets cancelled out
	int sub = sum_total - sum_arr;

	int sum_total_sq = 0;
	int sum_arr_sq = 0;

	for (int i = 0; i < n; i++) {

		sum_total_sq += pow(i, 2);
		sum_arr_sq += pow(arr[i], 2);

	}

	int add = (sum_total_sq - sum_arr_sq) / sub;
	//cout << add << endl;

	missing = (sub + add) / 2;
	duplicate = add - missing;

	cout << "Missing: " << missing << endl << "Duplicate: " << duplicate << endl;

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

	computeMissingDuplicateElement(arr, n);

}

