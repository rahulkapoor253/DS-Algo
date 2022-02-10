#include <bits/stdc++.h>

using namespace std;

int swapBits(int num, int bit1, int bit2) {

	//we only have to swap bits if they are different
	int val1 = num >> bit1 & 1;
	int val2 = num >> bit2 & 1;

	if (val1 == val2) {
		return num;
	}

	int res = (1 << bit1) | (1 << bit2);
	return res ^ num;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int num, bit1, bit2;
	cin >> num;
	cin >> bit1;
	cin >> bit2;

	cout << swapBits(num, bit1, bit2);

	return 0;
}




