#include <bits/stdc++.h>

using namespace std;

void addNumString(string str1, string str2) {

	if (str1.length() < str2.length()) {
		swap(str1, str2);
	}

	int len1 = str1.length();
	int len2 = str2.length();

	string res = "";

//it maintains str1 always the bigger string

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < len2; i++) {

		int val = (str1[i] - '0') + (str2[i] - '0') + carry;//handle exceeding case as well
		res.push_back( (val % 10)  + '0');
		carry = val / 10;
	}

	for (int i = len2; i < len1; i++) {

		int val = (str1[i] - '0') + carry;
		res.push_back( (val % 10) + '0');
		carry = val / 10;

	}

	if (carry > 0) {
		res.push_back(carry + '0');
	}

	reverse(res.begin(), res.end());
	cout << res << endl;

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

//this to_string and stoi can be used if string as number fits in long long int
	// int num1 = stoi(str1);
	// int num2 = stoi(str2);

	// int num3 = num1 + num2;
	// string res = to_string(num3);

	// cout << res;

	addNumString(str1, str2);

	return 0;
}




