#include <bits/stdc++.h>

using namespace std;

int spreadsheetConversion(string str) {

	//spreadsheet goes from A->Z, AA->ZZ and so on
	int len = str.length();
	int res = 0;

//base of 26
	for (int i = 0; i < len; i++) {
		res += (str[i] - 'A' + 1) * pow(26, len - 1 - i);
	}

	return res;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	cout << spreadsheetConversion(str) << endl;

	return 0;
}




