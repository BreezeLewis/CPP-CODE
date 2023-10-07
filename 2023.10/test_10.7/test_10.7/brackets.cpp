#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int flag = 1;

	string test = "{abc(good}  test)";
	string test1 = "[]{abc,(good) testtt}";

	string str = test1;

	stack<char> st;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
			st.push(str[i]);
		else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
		{
			if (st.empty())
			{
				flag = 0;
				break;
			}

			if (str[i] == '}')
			{

				if (st.top() == '{')
					st.pop();
				else
				{
					flag = 0;
					break;
				}
			}
			else if (str[i] == ')')
			{
				if (st.top() == '(')
					st.pop();
				else
				{
					flag = 0;
					break;
				}
			}
			else if (str[i] == ']')
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
		
	}

	if (!st.empty())
		flag = 0;

	cout << (flag == 1 ? "Yes\n" : "No\n") << endl;

	return 0;
}