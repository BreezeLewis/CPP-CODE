#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 10;
	vector<pair<int,bool>> v;
	v.reserve(2 * n);
	v.resize(n);
	for (int i = 0; i < n; i++)
		v[i].first = i + 1;
	int index = 0;
	int cnt = n;
	v[index].second = true;
	cout << v[index].first << " ";
	while (v.size())
	{
		for (int i = 0; i < 2; i++)
		{
			++index;
			if (index >= v.size())
			{
				index--;
				break;
			}
			if (v[index].second)
			{
				++index;
			}
		}
		v[index].second = true;
		cout << v[index].first << " ";
		if (index + 1 == v.size() - 1 || index == v.size() - 1)
		{
			auto tmp(v);
			v.clear();
			for (int i = 0; i < tmp.size(); i++)
			{
				if (tmp[i].second == false)
					v.push_back(tmp[i]);
			}
			if (v.empty())
				break;
			index = 0;
			cout << v[index].first << " ";
			v[index].second = true;
		}
	}

	return 0;
}