#include<algorithm>
#include<cstdio>
#include<iostream>
using std::sort;
int t, b[100001], d[100001], e[100001], s[100001], a[200001], u[200001], v[200001], st[200002];
//b[i]表示第i个点的出度
//d[i]表示第i个点的入度
//s[i]表示第i个点连的第一条边
//e[i]表示第i个点连的最后一条边
//st是栈
void dfs(int u)//求解
{
	int i;
	for (i = s[u]; i <= e[u]; i = s[u])
	{
		++s[u];//相当于去掉当前的边
		dfs(a[i]);
	}
	st[++t] = u;
}
int main()
{
	int f = 0, i, j = 0, k = 0, n, m, r = 1;
	//f记录上一个点的最后一个边的位置（如果不明白可以往下看看）
	//j记录出度比入度大1的点的个数
	//k记录入度比出度大1的点的个数
	//r表示起点，初始为1
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d", &u[i], &v[i]);
		++b[u[i]];
		++d[v[i]];
	}//读入并求出入度和出度
	for (i = 1; i <= n; ++i)
	{
		if (b[i] - d[i] > 1 || d[i] - b[i] > 1)//如果入度与出度相差大于1，那么不存在欧拉路径
		{
			puts("No");
			return 0;
		}
		if (b[i] - d[i] == 1)//出度比入度大1，作为起点
		{
			++j;
			r = i;
		}
		else if (d[i] - b[i] == 1)//入度比出度大1
			++k;
	}
	if ((j == 0 && k == 0) || (j == 1 && k == 1))//有解
	{
		for (i = 1; i <= n; ++i)
		{
			d[i] = s[i] = f + 1;
			//f是上一个点连的最后一个边，那么f+1就是这一个点的第一个边
			//d[i]作为临时变量，记录第i个点正在往数组里放第d[i]条边
			e[i] = f + b[i];//第i个点连的最后一个边
			f = e[i];//记录这一个点的最后一个位置
		}
		for (i = 1; i <= m; ++i)
			a[d[u[i]]++] = v[i];//按照起点分类
		for (i = 1; i <= n; ++i)
			sort(a + s[i], a + e[i] + 1);//对相同起点的数进行排序
		dfs(r);
		while (t)
			printf("%d ", st[t--]);
	}
	else//无解
		puts("No");
	return 0;
}