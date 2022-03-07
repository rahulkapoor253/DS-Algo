#include <bits/stdc++.h>

using namespace std;

int computeSquareRoot(int val) {

	int start = 0;
	int end = val;

	while (start <= end) {

		int mid = start + (end - start) / 2;
		int mid_sq = mid * mid;

		if (mid_sq == val) {
			return mid;
		}
		else if (mid_sq > val) {
			//right half can be discarded
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}

	}

	return start - 1;
}

int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	cout << computeSquareRoot(n);
	//binary search with limits [0,x] is valid in integers but not for floating numbers
	//as we limit the end value to x, whereeas sq.root of 1/4 will be 1/2 which is higher

}

