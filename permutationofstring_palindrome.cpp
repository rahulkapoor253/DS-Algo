#include <bits/stdc++.h>

using namespace std;


int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	//odd length then except 1 char all occurs in even
	//even length then all occurs in even times
	int len = str.length();
	unordered_map<char, int> umap;

	for (int i = 0; i < len; i++) {
		umap[str[i]]++;
	}

	int isOdd = 0;

	for (auto itr = umap.begin(); itr != umap.end(); itr++) {

		if (itr->second % 2 > 0) {
			isOdd++;
		}

	}

	if (isOdd == 0) {
		cout << "possible" << endl;
	}
	else if (isOdd == 1 && len % 2 > 0) {
		cout << "possible" << endl;
	}
	else {
		cout << "not possible" << endl;
	}

}

