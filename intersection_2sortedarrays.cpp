#include <bits/stdc++.h>

using namespace std;

void computeIntersection(int arr1[], int n1, int arr2[], int n2) {

	//Brute force to check one by one
	vector<int> res;

	// for (int i = 0; i < n2; i++) {

	// 	if ( (i == 0) || (arr2[i] != arr2[i - 1]) ) {

	// 		for (int j = 0; j < n1; j++) {

	// 			if (arr2[i] == arr1[j]) {
	// 				res.push_back(arr2[i]);
	// 				break;
	// 			}

	// 		}

	// 	}

	// }

	//to search element in the other list using Binary Search
	for (int i = 0; i < n2; i++) {

		if ( (i == 0) || (arr2[i] != arr2[i - 1]) ) {

			int key = arr2[i];
			int left = 0;
			int right = n1;

			while (left <= right) {

				int mid = left + (right - left) / 2;

				if (arr1[mid] == key) {
					res.push_back(arr2[i]);
					break;
				}
				else if (arr1[mid] > key) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}

			}

		}

	}

	//print vector
	for (auto itr = res.begin(); itr != res.end(); itr++) {
		cout << *itr << endl;
	}

}

void computeIntersectionOptimised(int arr1[], int n1, int arr2[], int n2) {

	vector<int> res;

	int ind1 = 0;
	int ind2 = 0;

	while (ind1 < n1 && ind2 < n2) {

//also handle ignoring the duplicates
		if ( (arr1[ind1] == arr2[ind2]) && (ind1 == 0 || arr1[ind1] != arr1[ind1 - 1]) ) {
			res.push_back(arr2[ind2]);
			ind1++;
			ind2++;
		}
		else if (arr1[ind1] > arr2[ind2]) {
			ind2++;
		}
		else {
			ind1++;
		}

	}

	//print vector
	for (auto itr = res.begin(); itr != res.end(); itr++) {
		cout << *itr << endl;
	}

}

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n1, n2;
	cin >> n1;
	cin >> n2;

	int arr1[n1];
	int arr2[n2];

	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}

	computeIntersection(arr1, n1, arr2, n2);
	cout << "Optimised" << endl;
	computeIntersectionOptimised(arr1, n1, arr2, n2);

	return 0;
}

