#include "Match.h"
#include <iomanip>


int main() {

	string brackets;
	cin >> brackets;

	size_t length = brackets.length();

	cout << "Origin brackets are :" << endl;
	cout << ">>> " << brackets << endl;
	cout << "Your judge on whether those brackets are matched is :" << endl;
	cout << ">>> " << boolalpha << Matched(brackets, length) << endl;

	return 0;
}
