#include <bits/stdc++.h>

using namespace std;

//parity of word is 1 if 1 bits are odd, else 0
int findParity(unsigned long x) {

	int count = 0;

	while (x > 0) {
		count += x & 1;
		x = x >> 1;
	}

	return count % 2;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	unsigned long x = pow(2, 63);

	cout << findParity(x);

	return 0;
}




