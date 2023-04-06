//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//string s[42], str, res;
//bool vis[42];
//int n;
//char head;
//int longest;
//int check(string s1, string s2)
//{
//	for (int i = s1.size() - 1; i >= 0; i--)
//		if (s1.substr(i) == s2.substr(0, s1.size() - i))
//			return s1.size() - i;
//	return -1;
//}
//void dfs(string ans, int dep)
//{
//	if (ans.size() > longest)
//		longest = ans.size(), res = ans;
//	if (dep == 2 * n + 1)
//		return;
//	for (int i = 1; i <= 2 * n; i++)
//		if (dep == 1 && s[i][0] == head && !vis[i])
//		{
//			vis[i] = 1;
//			dfs(ans + s[i], dep + 1);
//			vis[i] = 0;
//		}
//		else if (dep >= 2 && !vis[i])
//		{
//			int pos = check(ans, s[i]);
//			if (pos != -1)
//			{
//				vis[i] = 1;
//				dfs(ans + s[i].substr(pos), dep + 1);
//				vis[i] = 0;
//			}
//		}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> s[i];
//	for (int i = n + 1; i <= 2 * n; i++)
//		s[i] = s[i - n];
//	cin >> head;
//	dfs(str, 1);
//	cout << /*res << endl <<*/ longest << endl;
//	return 0;
//}