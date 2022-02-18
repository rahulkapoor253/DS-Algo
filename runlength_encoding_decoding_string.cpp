#include <bits/stdc++.h>

using namespace std;

void computeEncoding(string str) {

	string res = "";
	int len = str.length();
	int count = 0;
	int i = 1;

	while (i < len) {

		count = 1;

		while ( str[i] == str[i - 1] ) {
			count++;
			i++;
		}

		res += to_string(count) + str[i - 1];
		i++;
	}

	cout << res << endl;

}

void computeDecoding(string str) {

	string res = "";
	int len = str.length();

	//computing alternate values here
	for (int i = 1; i < len; i += 2) {

		int val = str[i - 1] - '0';
		res.append(val, str[i]);//it appends val copies of str[i] to result

	}

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

	//cout << str1 << endl << str2;
	computeEncoding(str1);
	computeDecoding(str2);


	return 0;
}




