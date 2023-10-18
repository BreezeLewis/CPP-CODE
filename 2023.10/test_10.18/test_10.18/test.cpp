#include "stack_sequence.h"

#include <iostream>
#include <string>
using namespace std;
using namespace lys;

int main()
{
	int t, n;
	string x, cmd;
	cin >> t;
	lys::stack<string, 1000010> st;
	while (t--)
	{
		st.clear();
		cin >> n;
		while (n--)
		{
			cin >> cmd;
			if (cmd == "push")
			{
				cin >> x;
				st.push(x);
			}
			else if (cmd == "pop")
			{
				if (st.empty())
					cout << "Empty" << endl;
				else
					st.pop();
			}
			else if (cmd == "query")
			{
				if (st.empty())
					cout << "Anguei!" << endl;
				else
					cout << st.top() << endl;
			}
			else if (cmd == "size")
			{
				cout << st.size() << endl;
			}
		}
	}


	return 0;
}