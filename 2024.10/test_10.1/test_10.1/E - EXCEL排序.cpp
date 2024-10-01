#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>

const int N = (int)1e5 + 10;

using namespace std;

struct student
{
	string id;
	string name;
	int score;
}stu[N];
int n, c, cnt;

using namespace std;

bool cmp(const student &x, const student &y)
{
	if (c == 1) return x.id < y.id;
	else if (c == 2)
	{
		if (x.name != y.name) return x.name < y.name;
		else return x.id < y.id;
	}
	else
	{
		if (x.score != y.score) return x.score < y.score;
		else return x.id < y.id;
	}
}

int main()
{
	while (scanf("%d%d", &n, &c) && n && c)
	{
		for (int i = 0; i < n; i++) cin >> stu[i].id >> stu[i].name >> stu[i].score;

		sort(stu, stu + n, cmp);

		printf("Case %d:\n", ++cnt);

		for (int i = 0; i < n; i++) printf("%s %s %d\n", stu[i].id.c_str(), stu[i].name.c_str(), stu[i].score);
	}

	return 0;
}

