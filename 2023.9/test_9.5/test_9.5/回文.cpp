#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string s = to_string(n);

	int left = 0, right = s.size() - 1;

	int flag = 1;

	while (left <= right)
	{
		if (s[left] != s[right])
		{
			flag = 0;
			break;
		}
	}
	
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}