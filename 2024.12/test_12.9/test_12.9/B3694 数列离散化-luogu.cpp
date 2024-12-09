#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = (int)1e5 + 10;

vector<int> alls;

int a[N];
int T, n;

int find(int x)
{
	int l = 0, r = (int)alls.size() - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;

	}
	return l + 1;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			alls.push_back(a[i]);
		}

		sort(alls.begin(), alls.end());
		alls.erase(unique(alls.begin(), alls.end()), alls.end());

		for (int i = 0; i < n; i++) cout << find(a[i]) << ' ';
		cout << endl;
		alls.clear();
	}

	return 0;
}