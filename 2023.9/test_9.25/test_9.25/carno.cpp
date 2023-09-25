#include <iostream>
#include <string>
using namespace std;

int main()
{
	for (int i = 1000; i < 10000; i++)
	{
		string ret = to_string(i);
		if (ret[0] == ret[1] && ret[2] == ret[3])
		{
			int tmp = (int)sqrt(i);
			if (tmp * tmp == i)
				cout << i << endl;
		}

	}

	return 0;
}