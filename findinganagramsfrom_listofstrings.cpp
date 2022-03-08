#include <bits/stdc++.h>

using namespace std;


int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	string arr[n];
	cin.ignore();//to skip enter from picking after integer

	for (int i = 0; i < n; i++) {
		string val;
		getline(cin, val);
		arr[i] = val;
	}

	//unorderedmap which takes key as sorted strings and values as list of str
	unordered_map<string, vector<string>> umap;

	for (int i = 0; i < n; i++) {

		string temp(arr[i]);
		sort(temp.begin(), temp.end());

		umap[temp].push_back(arr[i]);

	}

	vector<vector<string>> res;

	for (auto itr = umap.begin(); itr != umap.end(); itr++) {

		if (itr->second.size() >= 2) {
			res.push_back(itr->second);
		}

	}

	for (int i = 0; i < res.size(); i++) {

		for (auto itr = res[i].begin(); itr != res[i].end(); itr++) {
			cout << *itr << " ";
		}

		cout << endl;

	}

}

