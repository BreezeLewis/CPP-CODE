#include <iostream>
using namespace std;
int main()
{
	for (int i = 'X'; i <= 'Z'; i++)
	{
		for (int j = 'X'; j <= 'Z'; j++)
		{
			if (i != j)
			{
				for (int k = 'X'; k <= 'Z'; k++)
				{
					if (i != k && j != k)
					{
						if (i != 'X' && k != 'X' && k != 'Z')
						{
							cout << "A��" << (char)i << "��" << endl;
							cout << "B��" << (char)j << "��" << endl;
							cout << "C��" << (char)k << "��" << endl;
						}
					}
				}
			}
		}
	}

	return 0;
}