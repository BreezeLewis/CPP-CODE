//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//using namespace std;
//
//const int N = 1000010;
//
//char s[N], p[N];
//
//int ne[N];
//
//int main()
//{
//	int cnt = 0;
//	int first = 0;
//	int flag = 0;
//	cin >> p + 1;
//	getchar();
//	cin.getline(s + 1, N);
//	int Plen = (int)strlen(p + 1);
//	int Slen = (int)strlen(s + 1);
//
//	for (int i = 1; i <= Plen; i++)
//		p[i] = tolower(p[i]);
//	for (int i = 1; i <= Slen; i++)
//		s[i] = tolower(s[i]);
//
//	//ÇónextÊý×é
//	for (int i = 2, j = 0; i <= Plen; i++)
//	{
//		while (j && p[i] != p[j + 1])
//			j = ne[j];
//		if (p[i] == p[j + 1])
//			j++;
//		ne[i] = j;
//	}
//
//	for (int i = 1, j = 0; i <= Slen; i++)
//	{
//		while (j && s[i] != p[j + 1]) j = ne[j];
//		if (s[i] == p[j + 1]) j++;
//		if (j == Plen && (i - Plen + 1 == 1 || s[i - Plen] == ' ') && (i == Slen || s[i + 1] == ' '))
//		{
//			cnt++;
//			//printf("%d\n", i - Plen + 1);
//			if (flag == 0)
//			{
//				first = i - Plen;
//				flag = 1;
//			}
//			j = ne[j];
//		}
//	}
//
//	if (cnt == 0)
//		cout << -1 << endl;
//	else
//		cout << cnt << " " << first << endl;
//
//	return 0;
//}

/*
To
to be or not to be is a question
*/   //2 0

/*
to
Did the Ottoman Empire lose its power at that time
*/   //-1

/*
ABABABC
ABA
*/

/*
ABABABAABABAAABABAA
ABABABABABABAB
*/

//#include <iostream>
//#include <cstring>
//#include <cstdio>
//using namespace std;
//
//const int N = 1000010;
//
//char sentence[N];
//
//void strlower(char* a)
//{
//	for (int i = 0; a[i]; i++) 
//	{
//		if (isupper(a[i])) a[i] = tolower(a[i]);
//	}
//}
//
//
//
//int main()
//{
//	int first = 0;
//	int cnt = 0;
//	int flag = 0;
//	char word[20];
//	cin >> word;
//	getchar();
//	cin.getline(sentence, N);
//
//	int len1 = (int)strlen(word);
//	int len2 = (int)strlen(sentence);
//
//	strlower(word);
//	strlower(sentence);
//
//	char* p = sentence;
//	char* q = sentence;
//	while (p = strstr(q, word))
//	{
//		if (p != nullptr 
//			&& (p == sentence || *(p - 1) == ' ') 
//			&& (*(p + len1) == '\0' || *(p + len1) == ' '))
//		{
//			cnt++;
//			if (flag == 0)
//			{
//				flag = 1;
//				first = (int)(p - sentence);
//			}
//		}
//
//		q = p + len1;
//	}
//
//	if (flag == 0)
//	{
//		cout << -1;
//	}
//	else
//	{
//		cout << cnt << " " << first;
//	}
//	
//	return 0;
//}


