/*
5
a
b
c
ad
acd
3
a
a
e
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	unordered_map<string, string> um;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		um.insert(make_pair(s, "OK"));
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (um.count(s))
		{
			cout << um[s] << endl;
			um[s] = "REPEAT";
		}
		else
			cout << "WRONG" << endl;
	}

	return 0;
}