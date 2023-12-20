#include <iostream>
#include <vector>
using namespace std;

/*
���ڸ���������ͼ���жϸ�����������Ƿ�Ϸ�����������

�������һ������ͼ�����ɽ�����С�

һ������ͼ�ĵ�һ���ǽ����n�ͱ���m��Ȼ����m�����ԡ�

��������һ��������M����ʾ���������Ŀ��Ȼ����M�У�ÿ�и���һ��������򣬽��֮���ÿո�ָ���
*/

class Graph
{
	int V;//�ڵ���
	vector<vector<int>> adj;//�ڽӱ�
	vector<int> vis;
public:
	Graph(int V) : V(V)
	{
		adj.resize(V);
		vis.resize(V);
	}

	void addEdge(int u, int v)//����ͼ��ӱ�
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