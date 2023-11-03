//#include <iostream>
//#include <string>
//#include <set>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	string ret;
//	set<string> s;
//
//	while (n--)
//	{
//		cin >> ret;
//		s.insert(ret);
//	}
//
//	cout << s.size();
//
//	return 0;
//}



#include <iostream>
#include <string>
#include <set>

using namespace std;

const int base = 13313;

const int mod = 1223569421;

int myhash(string s)
{
	long long res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		res = (res * base + s[i] - 'a') % mod;
	}
	return (int)res;
}

int main()
{
	int n;
	cin >> n;
	set<int> s;
	string tmp;
	while (n--)
	{
		cin >> tmp;
		s.insert(myhash(tmp));
	}

	cout << s.size() << endl;

	return 0;
}