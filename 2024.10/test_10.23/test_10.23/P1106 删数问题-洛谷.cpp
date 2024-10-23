#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int n;

	cin >> str >> n;

	while (n--)
	{
		int size = (int)str.size();
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1 || str[i] > str[i + 1])
			{
				str.erase(i, 1);
				break;
			}
		}
	}

	while (str.size() > 1 && str[0] == '0')
		str.erase(0, 1);
	cout << str << endl;

	return 0;
}