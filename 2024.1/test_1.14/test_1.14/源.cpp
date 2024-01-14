#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct person
{
	string id;
	string name;
	int score;
};

bool sort_by_id(const person& x, const person& y)
{
	return x.id < y.id;
}

bool sort_by_name(const person& x, const person& y)
{
	if (x.name == y.name)
		return x.id < y.id;
	return x.name < y.name;
}

bool sort_by_score(const person& x, const person& y)
{
	if (x.score == y.score)
		return x.id < y.id;
	return x.score < y.score;
}

int main()
{
	int n, c, num = 0;
	while (cin >> n >> c && n && c)
	{
		vector<person> v(n, { "","",0 });
		for (int i = 0; i < n; i++)
			cin >> v[i].id >> v[i].name >> v[i].score;
		switch (c)
		{
		case 1:
		{
			sort(v.begin(), v.end(), sort_by_id);
			break;
		}
		case 2:
		{
			sort(v.begin(), v.end(), sort_by_name);
			break;
		}
		case 3:
		{
			sort(v.begin(), v.end(), sort_by_score);
			break;
		}
		}

		printf("Case %d:\n", ++num);
		for (const auto& e : v)
			cout << e.id << " " << e.name << " " << e.score << endl;
	}


	return 0;
}