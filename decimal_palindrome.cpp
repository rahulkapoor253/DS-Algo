#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int num) {
	int val = num;
	//negative number cant be palindrome
	if (num < 0) {
		return false;
	}
	//single digit num will always be palindrome
	if (num >= 0 && num < 10) {
		return true;
	}

	int res = 0;
	while (num > 0) {
		res = (res * 10) + (num % 10);
		num = num / 10;
	}

	if (res == val) {
		return true;
	}
	return false;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int digit;
	cin >> digit;

	cout << isPalindrome(digit);

	return 0;
}




