#include <bits/stdc++.h>

using namespace std;

string convertBase(string str, int base1, int base2) {

	int num = 0;
	string res = "";
	//check if base1 is already a base10
	if (base1 == 10) {
		num = stoi(str);
	}

	//convert to base10
	int i = 0;
	int len = str.length();
	int x;

	while (i < len) {

		if (str[i] >= 'A' && str[i] <= 'Z') {
			x = 10 + (str[i] - 'A');
		}
		else {
			x = str[i] - '0';
		}

		num += x * (pow(base1, len - 1 - i));
		i++;
	}

	if (base2 == 10) {
		res = to_string(num);
		return res;
	}

//conversion to base10 is * and +
//conversion from base10 is % and /

	while (num > 0) {

		int val = num % base2;

		if (val >= 10) {
			res.push_back('A' + val % 10);
		}
		else {
			res.push_back(val + '0');
		}

		num = num / base2;

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
	int base1, base2;

	getline(cin, str);
	cin >> base1;
	cin >> base2;

	//common bases are:
	//2 -> 0,1
	//8 -> 0-7
	//10 -> 0-9
	//16 -> hex -> 0-9, A-F

	cout << convertBase(str, base1, base2);

	return 0;
}




