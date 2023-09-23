#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

struct Node
{
	int id;
	int score;
};

bool cmp(Node x, Node y)
{
	if (x.score == y.score)
		return x.id < y.id;
	return x.score > y.score;
}

int main()
{
	cin >> n >> m;
	vector<Node> ret;
	ret.resize(n);
	int need = (int)(m * 1.5);
	for (int i = 0; i < n; i++)
	{
		cin >> ret[i].id >> ret[i].score;
	}

	sort(ret.begin(), ret.end(), cmp);

	int line = ret[need - 1].score;
	int last = need;
	while (ret[last].score >= line)
	{
		last++;
	}

	cout << line << " " << last << endl;

	for (int i = 0; i < last; i++)
	{
		cout << ret[i].id << " " << ret[i].score << endl;
	}

	return 0;
}