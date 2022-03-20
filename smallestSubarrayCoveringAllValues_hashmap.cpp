#include <bits/stdc++.h>

using namespace std;


int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n;
	cin >> m;

	cin.ignore();

	string arr[n];
	string str[m];
	string val;

	for (int i = 0; i < n; i++) {
		getline(cin, val);
		arr[i] = val;
	}

	for (int i = 0; i < m; i++) {
		getline(cin, val);
		str[i] = val;
	}

	//print data to test
	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << endl;
	// }

	// for (int i = 0; i < m; i++) {
	// 	cout << str[i] << endl;
	// }

	unordered_map<string, int> umap;

//store all the data of my set
	for (int i = 0; i < m; i++) {
		umap[str[i]]++;
	}

	int total_count = m;
	int minDist = INT_MAX;

	//now cover all set elements in arr to fix the right index, then keep closing left index
	int left = 0;
	int right = 0;

	for (right = 0; right < n; right++) {

		if ( (umap.find(arr[right]) != umap.end()) && (umap[arr[right]] > 0) ) {
			total_count--;
			umap[arr[right]]--;
		}

		//a scenario comes where right index covers all elements, then move left
		while (total_count == 0) {

			if ( (umap.find(arr[left]) != umap.end()) && (umap[arr[right]] == 0) ) {

				umap[arr[left]]++;//increase the count as this will become untravelled in next step
				total_count++;
				minDist = min(minDist, right - left);

			}

			left++;

		}

	}

	cout << minDist << endl;

}

