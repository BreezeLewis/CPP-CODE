#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;

struct node
{
	int level, order;
	bool operator < (const node other) const 
	{
		if (level == other.level) return order > other.order;
		return level < other.level;
	}
};

int main()
{
	ios::sync_with_stdio(false);

	while (cin >> n)
	{
		vector<priority_queue<node>> doc(4);
		int cnt = 0;
		while (n--)
		{
			string op;
			cin >> op;
			if (op == "IN")
			{
				cnt++; // ²¡ÈËID
				int x, y;
				cin >> x >> y;
				doc[x].push(node{ y, cnt });
			}
			else if (op == "OUT")
			{
				int x;
				cin >> x;
				if (doc[x].empty()) cout << "EMPTY" << endl;
				else
				{
					cout << doc[x].top().order << endl;
					doc[x].pop();
				}
			}
		}
	}

	return 0;
}