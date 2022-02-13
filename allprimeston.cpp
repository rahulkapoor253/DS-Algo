#include <bits/stdc++.h>

using namespace std;

bool checkPrime(int val) {

	if (val == 2 || val == 3) {
		return true;
	}

	for (int i = 2; i <= sqrt(val); i++) {
		if (val % i == 0) {
			return false;
		}
	}

	return true;
}

void computePrimes(int n) {

	for (int i = 2; i <= n; i++) {

		if (checkPrime(i)) {
			cout << i << endl;
		}

	}

}

void computePrimesSieving(int n) {

	bool arr[n + 1];
	vector<int> primes;

	for (int i = 0; i <= n; i++) {
		arr[i] = true;
	}

	for (int i = 2; i <= n; i++) {

		if (arr[i] == true) {
			primes.push_back(i);
			//make its multiple as false
			for (int k = i; k <= n; k += i) {
				arr[k] = false;
			}

		}

	}

	for (auto itr = primes.begin(); itr != primes.end(); itr++) {
		cout << *itr << endl;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n = 17;

	//computePrimes(n);
	computePrimesSieving(n);

	return 0;
}




