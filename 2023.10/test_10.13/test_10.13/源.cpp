#include <iostream>
#include <list>

using namespace std;

int main()
{

	int n, m;
	cin >> n >> m;

	list<int> l;
	for (int i = 1; i <= n; i++)
		l.push_back(i);

	auto it = l.begin();
	while (1)
	{
		if (l.size() == 1)
			break;
		int tmp = m;
		while (--tmp)
		{
			if (it == l.end())
			{
				it = l.begin();
				continue;
			}
			it = ++it;
			if (it == l.end())
			{
				it = l.begin();
			}
		}
		it = l.erase(it);
	}

	cout << *l.begin() << endl;

	return 0;
}