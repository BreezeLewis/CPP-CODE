#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool operator>(string x, string y)
{
	if (x.size() > y.size())
		return !(y > x);

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] > y[i])
			return true;
		else if (x[i] < y[i])
			return false;
	}
	if (x.size() == y.size())
		return false;
	string sub = y.substr(x.size());
	return x > sub;
}

bool compare(int x, int y)
{
	return to_string(x) > to_string(y);
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
		cout << v[i];



	return 0;
}