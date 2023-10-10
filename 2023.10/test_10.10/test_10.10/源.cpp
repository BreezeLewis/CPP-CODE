#include <iostream>
#include <stack>

using namespace std;

char a[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

int main()
{
	int num;
	int base;
	cin >> num >> base;

	stack<char> st;

	for (int i = num; i; i /= base)
	{
		st.push(a[i % base]);
	}

	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}

	return 0;
}