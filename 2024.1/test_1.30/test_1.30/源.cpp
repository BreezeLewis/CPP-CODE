#include<iostream>

using namespace std;

int main() {



	char* a = new char[101];

	cin >> a;

	int len = strlen(a) - 1;

	//aabbcbbaa

	for (int i = 0; i < len / 2; i++) {

		if (a[i] != a[len - i - 1]) {

			cout << "No";

			return 0;

		}

	}

	cout << "Yes";



	return 0;

}