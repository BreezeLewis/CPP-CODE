#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
	/*for (int i = 30; i < 100; i++)
	{
		if (i * i < 1000)
			continue;
		string s = to_string(i * i);

		if (s[0] == s[1] && s[2] == s[3])
			cout << s << endl;

	}*/

	/*int x;
	stack<int> st;

	while (cin >> x)
	{
		st.push(x);
	}

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}*/

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int x = v[0];
	for (int i = 0; i < v.size() - 1; i++)
		v[i] = v[i + 1];

	v[v.size() - 1] = x;

	for (const auto& e : v)
		cout << e << " ";

	return 0;
}