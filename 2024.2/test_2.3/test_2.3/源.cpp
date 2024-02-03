#include <iostream>
#include <stack>
#include <string>
using namespace std;
int pri[128];//pri[i]:�ַ�i�����ȼ�
void initPri()//��ʼ�����ŵ����ȼ�
{//�����Ŷ��������������Ŷ��Ǹ�������Ե����ŵ����ȼ���Ϊ�෴�� 
	pri['<'] = 1;
	pri['('] = 2;
	pri['['] = 3;
	pri['{'] = 4;
	pri['>'] = -1;
	pri[')'] = -2;
	pri[']'] = -3;
	pri['}'] = -4;
}
void solve()//���һ������ 
{
	stack<char> stk;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); ++i)
	{
		if (pri[s[i]] > 0)//���s[i]�������� 
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
		else//���s[i]�������� 
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
