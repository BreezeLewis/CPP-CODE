#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;
	int n;
	cin >> n;

	st.push(n);

	while (1)
	{
		char ch;
		scanf("%c", &ch);
		if (ch == '\n')
			break;

		cin >> n;
		if (ch == '+')
			st.push(n);
		else
		{
			int ret = (st.top() * n) % 10000;
			st.pop();
			st.push(ret);
		}
	}

	int ans = 0;
	while (!st.empty())
	{
		ans += st.top();
		ans %= 10000;
		st.pop();
	}

	cout << ans << endl;

	return 0;
}