#include <bits/stdc++.h>

using namespace std;


int main() {
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);

	string str;
	getline(cin, str);
	//string split on , delimeter
	stringstream ss(str);
	string token;
	char delim = ',';

	stack<int> st;

	while (getline(ss, token, delim)) {
		// cout << token << endl;
		if (token != "+" && token != "-" && token != "/" && token != "*") {

			int val = stoi(token);
			st.push(val);

		}
		else {

			//get the top 2 values which needs to be evaluated based on token as operator
			int val2 = st.top();
			st.pop();
			int val1 = st.top();
			st.pop();

			switch (token.front()) {

			case '+':
				st.push(val2 + val1);
				break;
			case '-':
				st.push(val1 - val2);
				break;
			case '/':
				st.push(val1 / val2);
				break;
			case '*':
				st.push(val1 * val2);
				break;

			}

		}

	}

	cout << st.top() << endl;

	return 0;
}
