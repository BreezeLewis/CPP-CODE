#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int getHash(string s)
{
	long long res = 0, base = 65535, mod = 1313133313;

	for (int i = 0; i < s.size(); i++) res = (res * base + (s[i] - 'a')) % mod;

	return (int)res;
}

int main()
{
	ios::sync_with_stdio(false);

	string s;
	unordered_map<int, string> spells, funcs;
	while (getline(cin, s))
	{
		if (s[0] == '@') break;

		int pos = (int)s.find(']') + 1;
		string spell = s.substr(0, pos);
		string func = s.substr(pos + 1);

		spells[getHash(spell)] = func;
		funcs[getHash(func)] = spell;

	}

	int n;
	cin >> n;
	getchar();

	while (n--)
	{
		string s;
		getline(cin, s);
		int value = getHash(s);

		if (s[0] == '[')
		{
			if (spells.count(value) > 0)
				cout << spells[value] << endl;
			else cout << "what?" << endl;
		}
		else
		{
			if (funcs.count(value) > 0)
			{
				string res = funcs[value];
				res = res.substr(1, res.size() - 2);
				cout << res << endl;
			}
			else cout << "what?" << endl;
		}
	}

	return 0;
}