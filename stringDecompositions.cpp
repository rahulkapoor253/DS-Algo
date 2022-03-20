#include <bits/stdc++.h>

using namespace std;


int main() {
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	cin.ignore();

	string sentence;
	getline(cin, sentence);

	string words[n];
	string val;

	for (int i = 0; i < n; i++) {

		getline(cin, val);
		words[i] = val;

	}

	int word_size = words[0].length();
	//all words are of same size: provided already
	unordered_map<string, int> umap;

	for (int i = 0; i < n; i++) {
		umap[words[i]]++;
	}

	int i = 0;
	int sentence_len = sentence.length();
	int end = sentence_len - (n * word_size);

//now the matching words should start from sentence length - total length of all words, else they are not present at all
	while ( i <= end ) {
		//take copy of hashmap to make changes
		unordered_map<string, int> temp_map(umap);
		int j = i;
		int curr_count = 0;

		while (j < i + (n * word_size) )  {

			string curr_word = sentence.substr(j, word_size);//to match any 1 of the word

			if ( (temp_map.find(curr_word) == temp_map.end()) || (temp_map[curr_word] == 0) ) {
				break;
			}
			else {
				temp_map[curr_word]--;
				curr_count++;
			}

			j += word_size;

		}

		//check the count, if == n then we have a match
		if (curr_count == n) {
			cout << i << endl;
		}

		i++;
	}


	return 0;
}

