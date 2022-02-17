#include <bits/stdc++.h>

using namespace std;

string computeLookAndSay(string str) {

	int count = 0;
	int i = 0;
	int len = str.length();
	string res = "";

	while (i < len) {

		count = 1;
		//to form groups
		while ( (i + 1 < len) && (str[i] == str[i + 1]) ) {
			count++;
			i++;
		}

		res += to_string(count) + str[i];
		i++;

	}

	return res;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	string str = "1";
	cout << str << endl;

//as first is calculated so start with 1->n
	for (int i = 1; i < n; i++) {
		//update the string as each iteration my new string becomes the last computed string
		str = computeLookAndSay(str);
		cout << str << endl;
	}

	return 0;
}




