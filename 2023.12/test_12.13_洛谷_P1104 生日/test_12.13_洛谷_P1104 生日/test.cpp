#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct person
{
	string name;
	int year, month, day;
	int id;
};

bool compare(const person& x, const person& y)
{
	if (x.year == y.year && x.month == y.month && x.day == y.day)
		return x.id > y.id;
	if (x.year == y.year && x.month == y.month)
		return x.day < y.day;
	if (x.year == y.year)
		return x.month < y.month;
	return x.year < y.year;
}

int main()
{
	int n;
	cin >> n;
	vector<person> v(n, { "",0,0,0,0 });

	for (int i = 0; i < n; i++)
		cin >> v[i].name >> v[i].year >> v[i].month >> v[i].day, v[i].id = i;

	sort(v.begin(), v.end(), compare);

	for (const auto& e : v)
		cout << e.name << endl;

	return 0;
}