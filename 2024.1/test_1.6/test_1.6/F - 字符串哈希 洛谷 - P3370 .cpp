#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_set<string> us;
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		us.insert(s);
	}

	cout << us.size() << endl;

	return 0;
}