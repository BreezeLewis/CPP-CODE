#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
struct stu
{
	string name;
	int score;
}a[20];
bool cmp(stu a, stu b)
{
	if (a.score == b.score)
		return a.name < b.name;
	return a.score > b.score;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].name >> a[i].score;
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
		cout << a[i].name << " " << a[i].score << endl;
	return 0;
}