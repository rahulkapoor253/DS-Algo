#include <bits/stdc++.h>

using namespace std;

int countBits(int x) {

	int count = 0;
	//say x = 5-> 0101
	while (x > 0) {
		count += x % 2;
		x = x / 2;
	}

	return count;
}

int countBitsShiftMask(int x) {

	int count = 0;
	while (x) {
		count += x & 1;//bitwise-AND, we will do for each bit and it returns 1 when bit is 1
		x = x >> 1;//shift x by one-bit
	}

	return count;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int x;
	cin >> x;

	cout << countBits(x) << endl;
	cout << countBitsShiftMask(x) << endl;

	return 0;
}




