#include <bits/stdc++.h>

using namespace std;


int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);

	stringstream ss(str);
	string token;
	char delim = '/';

	stack<string> st;

	// here word is directory name
	// here . is current directory
	// here .. is go to parent directory
	// here / is moving forward inside

	if (str[0] == '/') {
		//path is absolute
		st.push("/");
	}

	while (getline(ss, token, delim)) {
		//cout << token << endl;
		if (token == "..") {
			//move to parent directory
			if (!st.empty()) {
				st.pop();
			}

		}
		else if (token != "." && token != "" && token.length() >= 1) {
			//its name of directory
			st.push(token);
		}

	}

//reverse it to get path from front
	stack<string> res;

	while (!st.empty()) {

		res.push(st.top());
		st.pop();

	}

	string result = res.top();
	res.pop();

	while (!res.empty()) {

		string val = res.top();

		if (result == "/") {
			result += val;
		}
		else {
			result += "/" + val;
		}

		res.pop();
	}

	cout << result << endl;

	return 0;
}
