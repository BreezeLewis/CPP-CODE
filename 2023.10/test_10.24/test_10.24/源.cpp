#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
	int T, n, ret;
	cin >> T;
	while (T--)
	{
		cin >> n;
		unordered_map<int, int> unmap;
		vector<int> v;
		while (n--)
		{
			cin >> ret;
			
			if (!unmap.count(ret))
			{
				unmap[ret]++;
				v.push_back(ret);
			}
		}
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	return 0;
}