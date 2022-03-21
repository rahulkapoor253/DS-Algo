#include <bits/stdc++.h>

using namespace std;

struct Name {
	string firstName;
	string lastName;
};

bool comparer(const Name& x, const Name& y) {

	if (x.firstName != y.firstName) {
		return x.firstName < y.firstName;//return the smaller item as true
	}

	return x.lastName < y.lastName;
}

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	Name arr[n];
	string fname;
	string lname;

	cin.ignore();

	//unordered_map<string, string> umap;

	for (int i = 0; i < n; i++) {

		getline(cin, fname);
		getline(cin, lname);
		arr[i] = {fname, lname};

		// if (umap.find(fname) == umap.end()) {
		// 	umap[fname] = lname;
		// }

	}

//print map of names
	// for (auto itr = umap.begin(); itr != umap.end(); itr++) {
	// 	cout << itr->first << "," << itr->second << endl;
	// }

	sort(arr, arr + n, comparer);

	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i].firstName << ',' << arr[i].lastName << endl;
	// }

	int i = 0;//as first element can't be a duplicate of its own
	int j = 0;

	for (i = 0; i < n - 1; i++) {

		if (arr[i].firstName != arr[i + 1].firstName) {

			arr[j] = arr[i];
			j++;

		}

	}

	//now last element is pending to be considered
	arr[j] = arr[i];
	j++;

	for (int i = 0; i < j; i++) {
		cout << arr[i].firstName << ',' << arr[i].lastName << endl;
	}

	return 0;
}

