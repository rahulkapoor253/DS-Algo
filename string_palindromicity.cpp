#include <bits/stdc++.h>

using namespace std;

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	//BF will be to take new string and push all valid characters to it, post tht check palindrome

	//optimised
	int i = 0;
	int j = str.length() - 1;
	bool isPalindrome = true;

	while (i < j) {

		while (!isalnum(str[i]) && i < j) {
			i++;
		}

		while (!isalnum(str[j]) && j > i) {
			j--;
		}

		if (tolower(str[i]) != tolower(str[j])) {
			isPalindrome = false;
			break;
		}

		i++;
		j--;
	}

	if (isPalindrome) {
		cout << "Valid";
	}
	else {
		cout << "Not valid";
	}

	return 0;
}




