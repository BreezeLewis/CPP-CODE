#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000010;

char s[N], p[N];

int ne[N];

int main()
{
	cin >> s + 1 >> p + 1;
	int Plen = (int)strlen(p + 1);
	int Slen = (int)strlen(s + 1);

	//ÇónextÊı×é
	for (int i = 2, j = 0; i <= Plen; i++)
	{
		while (j && p[i] != p[j + 1]) 
			j = ne[j];
		if (p[i] == p[j + 1]) 
			j++;
		ne[i] = j;
	}

	for (int i = 1, j = 0; i <= Slen; i++)
	{
		while (j && s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) j++;
		if (j == Plen)
		{
			printf("%d\n", i - Plen + 1);
			j = ne[j];
		}
	}

	for (int i = 1; i <= Plen; i++)
		cout << ne[i] << " ";

	return 0;
}

/*
ABABABC
ABA
*/

/*
ABABABAABABAAABABAA
ABABABABABABAB
*/