//#include <iostream>
//using namespace std;
//int t, k;
//string s;
//int main()
//{
//	cin >> t;
//	while (t--)
//	{
//		cin >> s >> k;
//		while (k--)
//		{
//			for (int i = 0; i < s.size(); i++)
//			{
//				if (i == s.size() - 1)
//				{
//					s.erase(s.size() - 1, 1);
//					break;
//				}
//				if (s[i] > s[i + 1])
//				{
//					s.erase(i, 1);
//					break;
//				}
//			}
//		}
//		cout << s << endl;
//	}
//	return 0;
//}