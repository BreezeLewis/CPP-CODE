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
			cin >> vv[i][j];

	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
			cout << vv[i][j] << " ";
		cout << endl;
	}



	return 0;
}