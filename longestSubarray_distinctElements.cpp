#include <bits/stdc++.h>

using namespace std;


int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	cin.ignore();

	string arr[n];
	string val;

	for (int i; i < n; i++) {
		getline(cin, val);
		arr[i] = val;
	}

	unordered_map<string, int> umap;

	int left = 0;
	int right = 0;
	int maxDist = INT_MIN;

	for (right = 0; right < n; right++) {

		if (umap.find(arr[right]) == umap.end()) {

			umap[arr[right]] = right;//update to the index
			maxDist = max(maxDist, right - left + 1);

		}
		else {

			left = umap[arr[right]] + 1;
			maxDist = max(maxDist, right - left + 1);
			umap[arr[right]] = right;

		}

	}

	cout << maxDist << endl;

}

