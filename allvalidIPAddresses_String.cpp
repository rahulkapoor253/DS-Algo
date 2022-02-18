#include <bits/stdc++.h>

using namespace std;

bool isValidSubIP(string str) {

	int len = str.length();

	if (len > 3) {
		return false;
	}

//cant be 0 with other digits
	if (str[0] == '0' && len > 1) {
		return false;
	}

	int val = stoi(str);
	if (val >= 0 && val <= 255) {
		return true;
	}

	return false;
}

void computeAllValidIPBruteForce(string str) {

	int len = str.length();
	vector<string> res;

	string first = "";
	string second = "";
	string third = "";
	string fourth = "";

	for (int i = 1; i < 4 && i < len; i++) {

		first = str.substr(0, i);//index, number of chars to be picked
		//check validity
		if (isValidSubIP(first)) {

			for (int j = 1; j < 4 && i + j < len; j++) {

				second = str.substr(i, j);

				if (isValidSubIP(second)) {

					for (int k = 1; k < 4 && i + j + k < len; k++) {

						third = str.substr(i + j, k);

						if (isValidSubIP(third)) {

							fourth = str.substr(i + j + k);

							if (isValidSubIP(fourth)) {
								res.push_back(first + "." + second + "." + third + "." + fourth);
							}

						}

					}

				}

			}

		}

	}

//print all possible IP
	if (res.size() > 0) {
		for (auto itr = res.begin(); itr != res.end(); itr++) {
			cout << *itr << endl;
		}
	}
	else {
		cout << "No possible IP" << endl;
	}

}

void computeIP(string str, vector<string> &res, int start, int len, int level, string val) {

	if (start == len && level == 5) {
		res.push_back(val.substr(1));//to ignore the first .
	}

	for (int i = start; i < start + 3 && i < len; i++) {

		string temp = str.substr(start, i - start + 1);

		//check exit conditions
		if (str[i] == '0' && temp.length() > 1) {
			return;
		}

		if (stoi(temp) > 255) {
			return;
		}

		computeIP(str, res, i + 1, len, level + 1, val + "." + temp);

	}

}

void computeAllValidIPRecursion(string str) {

	vector<string> res;
	int len = str.length();

	computeIP(str, res, 0, len, 1, "");//also send level to keep track of how many subIP we have computed

	//print all possible IP
	if (res.size() > 0) {
		for (auto itr = res.begin(); itr != res.end(); itr++) {
			cout << *itr << endl;
		}
	}
	else {
		cout << "No possible IP" << endl;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	cout << "iterative solution" << endl;
	computeAllValidIPBruteForce(str);
	cout << "recursive solution" << endl;
	computeAllValidIPRecursion(str);

	return 0;
}




