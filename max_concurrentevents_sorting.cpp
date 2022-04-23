#include <bits/stdc++.h>

using namespace std;

struct Event {
	int start;
	int end;
};

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int s, e;
	Event arr[n];

	for (int i = 0; i < n; i++) {
		cin >> s;
		cin >> e;

		arr[i].start = s;
		arr[i].end = e;
	}

	int enter[n];
	int exit[n];

	for (int i = 0; i < n; i++) {

		enter[i] = arr[i].start;
		exit[i] = arr[i].end;

	}

	sort(enter, enter + n);
	sort(exit, exit + n);

	int idx1 = 0;
	int idx2 = 0;

	int curr = 0;
	int max_val = 0;

	while (idx1 < n && idx2 < n) {

		if (enter[idx1] <= exit[idx2]) {
			curr++;
			max_val = max(max_val, curr);
			idx1++;
		}
		else {
			curr--;
			idx2++;
		}

	}

	cout << max_val << endl;

	return 0;
}

