#include <iostream>

using namespace std;

const int N = 25;

char a[N][N];

int cnt, n, m;

void dfs(int sx, int sy)
{
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,-1,0,1};

	for (int i = 0; i < 4; i++)
	{
		int x = sx + dx[i], y = sy + dy[i];
		if (x < 0 || y < 0 || x >= n || y >= m)
			continue;

		if (a[x][y] != '.') continue;
		a[x][y] = '@';
		cnt++;
		dfs(x, y);
	}
}

int main()
{
	int x, y;
	while (cin >> m >> n && n && m)
	{
		cnt = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == '@')
					x = i, y = j;
			}
		}

		dfs(x, y);
		cout << cnt << endl;
		
	}
}