#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	
	while (t--)
	{
		stack<string> st;
		cin >> n;
		while (n--)
		{
			string s;
			cin >> s;
			if (s == "push")
			{
				string ret;
				cin >> ret;
				st.push(ret);
			}
			else if (s == "pop")
			{
				if (st.empty())
					cout << "Empty" << endl;
				else
					st.pop();
			}
			else if (s == "query")
			{
				if (st.empty())
					cout << "Anguei!" << endl;
				else
					cout << st.top() << endl;
			}
			else// if(s == "size")
			{
				cout << st.size() << endl;
			}
		}
		

	}

	return 0;
}