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
	string str;

	cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, str);
		arr[i] = str;
	}

	//print arr
	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << endl;
	// }

	unordered_map<string, int> umap;
	int nearestEntry = INT_MAX;

	for (int i = 0; i < n; i++) {

		//check if value exists in map or not
		if (umap.find(arr[i]) != umap.end()) {

			int old_index = umap[arr[i]];
			umap[arr[i]] = i;
			nearestEntry = min(nearestEntry, i - old_index);

		}
		else {
			umap[arr[i]] = i;
		}

	}

	cout << nearestEntry;

}

