#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string ret;
	unordered_map<string, string> m;
	while (n--)
	{
		cin >> ret;
		m[ret] = "OK";
	}

	int x;
	cin >> x;

	while (x--)
	{
		cin >> ret;
		if (m.count(ret))
		{
			cout << m[ret] << endl;
			m[ret] = "REPEAT";
		}
		else
			cout << "WRONG" << endl;
	}

	return 0;
}