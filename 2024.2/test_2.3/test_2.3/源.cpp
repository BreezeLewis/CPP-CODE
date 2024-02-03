#include <iostream>
#include <stack>
#include <string>
using namespace std;
int pri[128];//pri[i]:字符i的优先级
void initPri()//初始化括号的优先级
{//左括号都是正数，右括号都是负数，配对的括号的优先级互为相反数 
	pri['<'] = 1;
	pri['('] = 2;
	pri['['] = 3;
	pri['{'] = 4;
	pri['>'] = -1;
	pri[')'] = -2;
	pri[']'] = -3;
	pri['}'] = -4;
}
void solve()//求解一组数据 
{
	stack<char> stk;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); ++i)
	{
		if (pri[s[i]] > 0)//如果s[i]是左括号 
		{
			if (stk.empty())
				stk.push(s[i]);
			else
			{
				if (pri[s[i]] <= pri[stk.top()])
					stk.push(s[i]);
				else
				{
					cout << "NO" << endl;
					return;
				}
			}
		}
		else//如果s[i]是右括号 
		{
			if (stk.empty())
			{
				cout << "NO" << endl;
				return;
			}
			else
			{
				if (pri[s[i]] + pri[stk.top()] == 0)
					stk.pop();
				else
				{
					cout << "NO" << endl;
					return;
				}
			}
		}
	}
	if (stk.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
int main()
{
	initPri();
	int n;
	cin >> n;
	while (n--)
		solve();
	return 0;
}
