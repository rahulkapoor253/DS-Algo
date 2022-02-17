#include <bits/stdc++.h>

using namespace std;

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	reverse(str.begin(), str.end());

	int start = 0, end = 0;
	int len = str.length();

	while (end < len) {

		if (str[end] == ' ') {
			reverse(str.begin() + start, str.begin() + end);
			start = end + 1;
		}

		end++;
	}

	//last word needs to be handled manually as there is no ending ' '
	reverse(str.begin() + start, str.end());

	cout << str;

	return 0;
}




