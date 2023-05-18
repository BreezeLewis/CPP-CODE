#include <iostream>
#include <string>
using namespace std;
string s;
const int N = (int)1e9;
bool check(string s1, string s2)
{
	int a[10] = { 0 };
	int b[10] = { 0 };
	for (int i = 0; i < s1.size(); i++)
		a[s1[i] - '0']++;
	for (int i = 0; i < s2.size(); i++)
		b[s2[i] - '0']++;

	for (int i = 0; i < 10; i++)
	{
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}
int main()
{
	cin >> s;
	
	for (int i = 0;; i++)
	{
		int num = (int)pow(2, i);
		if (num > N)
		{
			cout << 0 << endl;
			break;
		}
		else
		{
			string s_num = to_string(num);
			int ret = check(s, s_num);
			if (ret)
			{
				cout << ret << endl;
				break;
			}
		}
	}
	
	return 0;
}