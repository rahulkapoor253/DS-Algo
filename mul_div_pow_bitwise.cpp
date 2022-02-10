#include <bits/stdc++.h>

using namespace std;

int bitwiseAdd(int num1, int num2) {

	while (num2 != 0) {
		int carry = num1 & num2;
		num1 = num1 ^ num2;
		num2 = carry << 1;
	}

	return num1;
}

int bitwiseMult(int num1, int num2) {

	//it works with shifting and adding concept
	int res = 0;

	while (num1) {

		if (num1 & 1) {
			res = bitwiseAdd(res, num2);
		}

		num2 = num2 << 1;
		num1 = num1 >> 1;//to exhaust it till 0
	}

	return res;
}

int bitwisePow(int x, int y) {

	int res = 1;
	//we need to multiply x with y-1 times of x
	while (y) {

		if (y & 1) {
			res = res * x;
		}

		x = x * x;
		y = y >> 1;

	}

	return res;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	cout << bitwiseAdd(15, 32) << endl;
	cout << bitwiseMult(13, 9) << endl;
	cout << bitwisePow(2, 3) << endl;

	return 0;
}




