#include <bits/stdc++.h>

using namespace std;

void replaceandRemove(char arr[], int n) {
	//its easier to remove b first as a are taking extra spaces to adjust 2d's
	int i = -1;
	int j = 0;
	int count_a = 0;

	while (j < n) {

		if (arr[j] == 'b') {
			j++;
		}
		else {

			if (arr[j] == 'a') {
				count_a++;
			}

			i++;
			arr[i] = arr[j];
			j++;
		}

	}

	//bring j to the last index
	j = i + count_a;
	int curr = i;
	int final_size = j + 1;

	while (curr >= 0) {

		if (arr[curr] == 'a') {
			curr--;

			arr[j] = 'd';
			j--;
			arr[j] = 'd';
			j--;
		}
		else {
			arr[j] = arr[curr];
			j--;
			curr--;
		}

	}

	//print array
	for (int i = 0; i < final_size; i++) {
		cout << arr[i] << endl;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	char arr[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	replaceandRemove(arr, n);

	return 0;
}




