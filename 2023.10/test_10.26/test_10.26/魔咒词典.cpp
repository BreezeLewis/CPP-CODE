#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int base = 13313;
int mode = (int)1e9 + 7;

int myhash(string s)
{
	long long ret = 0;
	for (const auto& e : s)
	{
		ret = (ret * base + e - 'a') % mode;
	}
	return (int)ret;
}

int main()
{
	unordered_map<int, string> spell;
	unordered_map<int, string> fun;
	string s;
	while (getline(cin, s) && s != "@END@")
	{
		int pos = (int)s.find(']');

		string spe = s.substr(1, pos - 1);
		string f = s.substr(pos + 2);

		spell[myhash(spe)] = f;
		fun[myhash(f)] = spe;
	}

	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		getline(cin, s);
		if (s[0] == '[')
		{
			int val = myhash(s.substr(1, s.size() - 2));
			if (spell.count(val))
				cout << spell[val] << endl;
			else
				cout << "what?" << endl;
		}
		else
		{
			int val = myhash(s);
			if (fun.count(val))
				cout << fun[val] << endl;
			else
				cout << "what?" << endl;
		}
	}

	return 0;
}


/*
[expelliarmus] the disarming charm
[rictusempra] send a jet of silver light to hit the enemy
[tarantallegra] control the movement of one's legs
[serpensortia] shoot a snake out of the end of one's wand
[lumos] light the wand
[obliviate] the memory charm
[expecto patronum] send a Patronus to the dementors
[accio] the summoning charm
@END@
4
[lumos]
the summoning charm
[arha]
take me to the sky
*/