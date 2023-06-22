#include <iostream>
#include <string>
#include <queue>
#include "mystack.h"

using namespace std;

void print(mystack& st) {
	while (!st.empty()) {
		int tmp = st.pop();
		cout << tmp << ' ';
	}
	cout << endl;
}

int main() {
	mystack st;

	int n;
	cin >> n;
	while (n--) {
		string op;
		cin >> op;

		if (op == "push") {
			int x;
			cin >> x;
			st.push(x);
			cout << "push " << x << endl;
		}
		else if (op == "pop") {
			int res = st.pop();
			if (res == -1) {
				cout << "pop failed" << endl;
			}
			else {
				cout << "pop " << res << endl;
			}
		}
		else if (op == "top") {
			int res = st.top();
			if (res == -1) {
				cout << "top failed" << endl;
			}
			else {
				cout << "top " << res << endl;
			}
		}
		else if (op == "empty") {
			if (st.empty()) {
				cout << "st empty" << endl;
			}
			else {
				cout << "st not empty" << endl;
			}
		}
	}
	print(st);

	return 0;
}
