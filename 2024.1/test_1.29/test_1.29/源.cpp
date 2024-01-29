#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> vv(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> vv[i][j];
			if (vv[i][j])
				cout << i + 1 << " " << j + 1 << " " << vv[i][j] << endl;
		}
	

	

	return 0;
}