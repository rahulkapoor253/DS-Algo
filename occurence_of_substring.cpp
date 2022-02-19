#include <bits/stdc++.h>

using namespace std;

bool computeOccurenceOfSubstringBF(string text, string str) {

	int i = 0;
	int j = 0;
	int len_text = text.length();
	int len_str = str.length();

	int ind = 0;

	while (i < len_text) {

		if (text[i] == str[0]) {

			j = 0;
			ind = i;

			while (j < len_str && i < len_text && text[i] == str[j]) {

				i++;
				j++;

			}

			if (j == len_str) {
				return true;
			}

			i = ind;

		}
		else {
			i++;
		}

	}

	return false;
}

void computeRabinKarp(string str, string pat) {

	//d size 26
	int d = 26;
	int q = 101;
	int len_text = str.length();
	int len_pat = pat.length();

	int hash_pat = 0;
	int hash_text = 0;
	int h = 1;

	for (int i = 0; i < len_pat - 1; i++) {
		h = (h * d) % q;
	}

	//calculate hash of both pattern and first text
	for (int i = 0; i < len_pat; i++) {

		hash_pat = (hash_pat * d + (pat[i])) % q;
		hash_text = (hash_text * d + (str[i])) % q;

	}

	//cout << hash_pat << endl;

	int i = 0;

	while ( (i < len_text) && (i + len_pat - 1 < len_text) ) {

		if (hash_text == hash_pat) {
			int j = i;
			int k = 0;

			while (k < len_pat && j < len_text  && str[j] == pat[k]) {
				j++;
				k++;
			}

			if (k >= len_pat) {
				cout << str.substr(i, len_pat) << endl;
			}

		}

		//compute rolling hash here
		hash_text = ((hash_text - (h * (str[i]))) * d + (str[i + len_pat])) % q;
		if (hash_text < 0) {
			hash_text = hash_text + q;
		}
		//cout << hash_text << endl;
		i++;
	}

}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string text, str;
	getline(cin, text);
	getline(cin, str);

	//cout << computeOccurenceOfSubstringBF(text, str) << endl;
	computeRabinKarp(text, str);

	return 0;
}




