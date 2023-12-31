#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<char> st;
	int flag = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == '[')
			st.push(s[i]);
		else if (st.empty())
		{
			flag = 0;
			break;
		}
		else if (s[i] == ')')
		{

			if (st.top() == '(')
				st.pop();
			else
			{
				flag = 0;
				break;
			}
		}
		else
		{
			if (st.top() == '[')
				st.pop();
			else
			{
				flag = 0;
				break;
			}
		}
	}

	if (!st.empty())
		flag = 0;

	if (flag)
		cout << "OK" << endl;
	else
		cout << "Wrong" << endl;

	return 0;
}