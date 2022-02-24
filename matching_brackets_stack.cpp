#include <bits/stdc++.h>

using namespace std;

bool matchingBrackets(string str) {
//to match it we use stack push and pop and brackets should open-close in pairs
	stack<char> st;
	int len = str.length();

	for (int i = 0; i < len; i++) {

		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			st.push(str[i]);
		}
		else {

			if (st.empty()) {
				return false;
			}
			else {

				char bracket_val = st.top();

				if ( (str[i] == ')' && bracket_val != '(') ||
				        (str[i] == ']' && bracket_val != '[') ||
				        (str[i] == '}' && bracket_val != '{') ) {
					return false;
				}

				st.pop();
			}

		}

	}

	if (!st.empty()) {
		return false;
	}

	return true;
}

int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	cout << matchingBrackets(str);

	return 0;
}
