#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> num;

// asd764rt143,fg6746
int main()
{
	string s;

	cin >> s;

	int i = 0;

	int flag = 0;

	while (1)
	{
		if (i == s.size())
			break;

		

		while (s[i] >= '0' && s[i] <= '9')
		{
			num.push_back(s[i++]);
		}

		if (!num.empty())
		{
			if (flag == 0)
				flag = 1;
			else
				cout << ',';

			for (auto& e : num)
				cout << e ;

			num.clear();
		}
		else
			i++;
	}

	cout << endl;

	return 0;
}