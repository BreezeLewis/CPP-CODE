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
							cout << "A和" << (char)i << "比" << endl;
							cout << "B和" << (char)j << "比" << endl;
							cout << "C和" << (char)k << "比" << endl;
						}
					}
				}
			}
		}
	}

	return 0;
}