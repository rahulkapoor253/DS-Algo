#include <bits/stdc++.h>

using namespace std;

int reverseDigits(int num) {

	int res = 0;
	bool isNegative = false;//handle negative scenario as well

	if (num < 0) {
		isNegative = true;
		num = abs(num);
	}

	while (num > 0) {
		res = res * 10 + num % 10;
		num = num / 10;
	}

	return isNegative ? -res : res;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int digit;
	cin >> digit;

	cout << reverseDigits(digit);

	return 0;
}




