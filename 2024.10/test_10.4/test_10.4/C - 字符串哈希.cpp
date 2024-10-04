#include <iostream>
#include <string>
#include <set>

using namespace std;

int getHash(string s)
{
	int res = 0, base = 31, mod = 1313133313;
	for (int i = 0; i < s.size(); i++) res = (res * base + (s[i] - 'a')) % mod;

	return res;
}

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	set<int> res;
	while (n--)
	{
		string s;
		cin >> s;
		res.insert(getHash(s));
	}

	cout << res.size() << endl;

	return 0;
}