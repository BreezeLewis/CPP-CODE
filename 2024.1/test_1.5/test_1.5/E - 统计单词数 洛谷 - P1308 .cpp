#include <iostream>
#include <string>
#include <vector>

/*
To
to be or not to be is a question
*/

/*
2 0
*/

using namespace std;

int main()
{
	int cnt = 0, pos = 0;
	string text, pattern;
	cin >> pattern;
	getchar();
	getline(cin, text);
	for (auto& e : text)
		if (e >= 'A' && e <= 'Z')
			e += 32;
	for (auto& e : pattern)
		if (e >= 'A' && e <= 'Z')
			e += 32;

	int n = (int)text.size(), m = (int)pattern.size();
	vector<int> next(m, 0);
	int j = 0;
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = next[j - 1];
		if (pattern[i] == pattern[j])
			j++;
		next[i] = j;
	}

	j = 0;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		while (j > 0 && text[i] != pattern[j])
			j = next[j - 1];
		if (text[i] == pattern[j])
			j++;
		if (j == m)//模式串匹配完毕
		{
			if (i == n - 1 || text[i + 1] == ' ')//目标串走完，或者下一个为空格，表明匹配到了单词的尾部
			{
				if (i - m < 0 || text[i - m] == ' ')//目标串的第一个单词
				{
					j = next[j - 1];
					cnt++;
					if (flag == 0)
						pos = i - m + 1, flag = 1;
				}
			}
		}
	}

	if (cnt)
		cout << cnt << " " << pos << endl;
	else
		cout << -1 << endl;

	return 0;
}