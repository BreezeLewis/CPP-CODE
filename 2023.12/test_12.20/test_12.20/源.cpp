#include <iostream>
#include <vector>
using namespace std;

/*
对于给定的有向图，判断给定结点序列是否合法的拓扑排序。

输入包含一个有向图和若干结点序列。

一个有向图的第一行是结点数n和边数m，然后是m个结点对。

接下来是一个正整数M，表示结点序列数目，然后是M行，每行给出一个结点排序，结点之间用空格分隔。
*/

class Graph
{
	int V;//节点数
	vector<vector<int>> adj;//邻接表
	vector<int> vis;
public:
	Graph(int V) : V(V)
	{
		adj.resize(V);
		vis.resize(V);
	}

	void addEdge(int u, int v)//有向图添加边
	{
		adj[u].push_back(v);
	}

	bool isTopoSequence(vector<int>& v)
	{
		
		for (auto e: v)
		{
			for (int i = 0; i < adj.size(); i++)
			{
				if (vis[i])
					continue;
				for (int j = 0; j < adj[i].size(); j++)
				{
					if (adj[i][j] == e)
						return false;
				}
			}
			vis[e] = 1;
		}
		return true;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	Graph g(n);

	int u, v;
	while (m--)
	{
		cin >> u >> v;
		g.addEdge(u, v);
	}

	
	cin >> m;
	while (m--)
	{
		auto tmp(g);
		vector<int> v;
		int ret;
		for (int i = 0; i < n; i++)
		{
			cin >> ret;
			v.push_back(ret);
		}

		if (tmp.isTopoSequence(v))
			cout << "OK" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}