#include <bits/stdc++.h>

using namespace std;

void computeMnemonics(string str, unordered_map<int, string> umap, string res, int ind, int n) {

	if (ind == n) {
		cout << res << endl;
		return;
	}

	int digit = str[ind] - '0';

	//recurse from that map loop
	string temp = umap[digit];
	int temp_len = temp.length();

	for (int i = 0; i < temp_len; i++) {

		//as we are making combination of result strings so add values to res, and move ahead in ind
		computeMnemonics(str, umap, res + temp[i], ind + 1, n);

	}

}


int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	int len = str.length();
	string res = "";

	unordered_map<int , string> umap;
	umap[0] = "0";
	umap[1] = "1";
	umap[2] = "ABC";
	umap[3] = "DEF";
	umap[4] = "GHI";
	umap[5] = "JKL";
	umap[6] = "MNO";
	umap[7] = "PQRS";
	umap[8] = "TUV";
	umap[9] = "WXYZ";

	computeMnemonics(str, umap, res, 0, len);

	return 0;
}




