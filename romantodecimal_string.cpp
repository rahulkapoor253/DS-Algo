#include <bits/stdc++.h>

using namespace std;


int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	unordered_map<char, int> umap;

	umap['I'] = 1;
	umap['V'] = 5;
	umap['X'] = 10;
	umap['L'] = 50;
	umap['C'] = 100;
	umap['D'] = 500;
	umap['M'] = 1000;

	int res = 0;
	int len = str.length();

	for (int i = 0; i < len; i++) {

		if ( (i + 1 < len) && (umap[str[i]] >= umap[str[i + 1]]) ) {
			//add normally and move ahead
			res += umap[str[i]];
		}
		else {
			//subtract this value and add next value to the res
			res -= umap[str[i]];
			i++;
			res += umap[str[i]];
		}

	}

	cout << res << endl;

	return 0;
}




