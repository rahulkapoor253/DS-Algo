#include <bits/stdc++.h>

using namespace std;

struct Interval {
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
	Interval arr[n];

	for (int i = 0; i < n; i++) {
		cin >> s;
		cin >> e;

		arr[i].start = s;
		arr[i].end = e;
	}

	int new_start, new_end;

	cin >> new_start;
	cin >> new_end;

	Interval new_int;
	new_int.start = new_start;
	new_int.end = new_end;

	vector<Interval> res;

	//traverse each interval and find if it intersects at any point with the new interval to be added
	for (int i = 0; i < n; i++) {

		if (arr[i].start >= new_int.start && arr[i].start <= new_int.end) {

			//take union of both intervals
			new_int.start = min(new_int.start, arr[i].start);
			new_int.end = max(new_int.end, arr[i].end);

		}
		else if (arr[i].end >= new_int.start && arr[i].end <= new_int.end) {

			//take union of both intervals
			new_int.start = min(new_int.start, arr[i].start);
			new_int.end = max(new_int.end, arr[i].end);

		}
		else {
			//not part of intersection
			res.push_back(arr[i]);
		}

	}

	res.push_back(new_int);

	for (auto itr = res.begin(); itr != res.end(); itr++) {
		cout << itr->start << " " << itr->end << endl;
	}

	//cout << new_int.start << " " << new_int.end << endl;

	return 0;
}

