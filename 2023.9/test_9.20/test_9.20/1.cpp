#include <iostream>
#include <vector>
using namespace std;

int n, m;

struct mynode
{
	int score;
	int id;
};
int main()
{
	vector<mynode> ret;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		mynode node;
		cin >> node.id;
		node.score = -1;
		ret.push_back(node);
	}

	for (int i = 0; i < m; i++)
	{
		int id; cin >> id;
		int score; cin >> score;
		for (int j = 0; j < n; j++)
		{
			if (ret[j].id == id)
			{
				ret[j].score = score;
				break;
			}

		}
	}
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if (ret[i].score == -1)
			a++, b++;
		else if (ret[i].score < 60)
			b++;
	}
	cout << a << endl << b << endl;

	return 0;
}