#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i]) return a[i] < b[i];
}

int main()
{
	int n, r;
	cin >> n >> r;
	vector<vector<int>> ans;

	for (int i = 0; i < (1 << n); i++)
	{
		int cnt = 0;
		for (int j = 0; j <= n; j++)
			if (i & (1 << j)) cnt++;

		if (cnt == r)
		{
			vector<int> tmp;
			for (int j = 0; j <= n; j++)
				if (i & (1 << j)) tmp.push_back(j + 1);

			ans.push_back(tmp);
		}


	}

	sort(ans.begin(), ans.end(), cmp);

	for (auto v : ans)
	{
		for (auto e : v)
			cout << setw(3) << e;
		cout << endl;
	}
}
