#include <bits/stdc++.h>

using namespace std;

void incrementNum(vector<int> arr, int n) {

	int i;
	for (i = n - 1; i >= 0; i--) {

		if (arr[i] < 9) {
			arr[i] = arr[i] + 1;
			break;
		}
		else if (arr[i] == 9) {
			arr[i] = 0;
		}

	}

	//if i is on 0th index, it means all digits were 9
	if (i < 0) {
		arr.insert(arr.begin(), 1);
	}

	for (auto itr = arr.begin(); itr != arr.end(); itr++) {
		cout << *itr << endl;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n, val;
	cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> val;
		arr.push_back(val);
	}

	incrementNum(arr, n);

	return 0;
}




