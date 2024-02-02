#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_mate(string& s)
{
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '{' || s[i] == '(' || s[i] == '<' || s[i] == '[')
		{
			st.push(s[i]);
			continue;
		}
		
		if (st.empty())
			return false;

		char top = st.top(); // »ñÈ¡Õ»¶¥ÔªËØ

		if (s[i] == '}' && top == '{')
			st.pop();
		else if (s[i] == ')' && top == '(')
			st.pop();
		else if (s[i] == '>' && top == '<')
			st.pop();
		else if (s[i] == ']' && top == '[')
			st.pop();
		else
			return false;
	}

	return st.empty();
}

int main()
{
	int n;
	cin >> n;

	string s;
	//cin >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (is_mate(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

