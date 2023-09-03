#include <iostream>
#include <map>

using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char, int> m;
	for (int i = 0; i < s.size(); i++)
	{
		m[s[i]]++;
	}

	auto it = m.begin();

	while (it != m.end())
	{
		cout << it->first << "=" << it->second << endl;;
		it++;
	}

	return 0;
}