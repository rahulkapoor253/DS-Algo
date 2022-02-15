#include <bits/stdc++.h>

using namespace std;

int string_to_int(string str) {
	//stoi()

	bool isNegative = false;
	int i = 0;
	int res = 0;

	if (str[0] == '-') {
		isNegative = true;
		i++;
	}

	while (i < str.length()) {

		int num = str[i] - '0';
		res = res * 10 + num;
		i++;

	}

	if (isNegative) {
		res = res * -1;
	}

	return res;
}

string int_to_string(int val) {
	//to_string()
	bool isNegative = false;

	if (val == 0) {
		return "0";
	}

	if (val < 0) {
		isNegative = true;
		val = val * -1;
	}

	string res = "";
	while (val > 0) {

		res.push_back(val % 10 + '0');
		val = val / 10;

	}

	if (isNegative) {
		res.push_back('-');
	}

	reverse(res.begin(), res.end());

	return res;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	cout << string_to_int(str) << endl;

	int val;
	cin >> val;

	cout << int_to_string(val) << endl;

	return 0;
}




