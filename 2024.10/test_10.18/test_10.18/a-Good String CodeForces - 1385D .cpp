#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string str;
int solve(int l, int r, int c)
{
	if (l == r)
	{
		if (c == str[l]) return 0;
		return 1;
	}

	int left = 0, right = 0;
	int mid = (l + r) >> 1;

	for (int i = l; i <= mid; i++)
		if (str[i] != c) left++;

	for (int i = mid + 1; i <= r; i++)
		if (str[i] != c) right++;

	return min(left + solve(mid + 1, r, c + 1), right + solve(l, mid, c + 1));

}

int main()
{
	int T, n;
	cin >> T;

	while (T--)
	{
		cin >> n >> str;

		cout << solve(0, n - 1, 'a') << endl;
	}

	return 0;
}