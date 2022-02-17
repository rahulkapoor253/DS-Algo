#include <bits/stdc++.h>

using namespace std;

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	int len = str.length();
	string res = "";

	int start = 0;
	int end = len - 1;

	while (start >= 0 && end >= 0) {

		while (end >= 0 && str[end] == ' ') {
			end--;
		}

		start = end;

		while (start >= 0 && str[start] != ' ') {
			start--;
		}


		string val =  str.substr(start + 1, end - start);
		if (val.length() >= 1) {
			res += val;
			res += " ";
		}

		end = start;
	}

	res.pop_back();

	cout << res;

	return 0;
}




