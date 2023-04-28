#include <iostream>
using namespace std;
char* trim(char* str);
int main()
{
	char s[1024] = { 0 };;
	cin.getline(s, 1024);
	cout << trim(s) << endl;
	return 0;
}
char* trim(char* str)
{
	char* p;
	p = str + 10;
	while (*p == ' ' || *p == '\0')
	{
		*p = '\0';
		p--;
	}
	p = str;
	while (*p == ' ')
		p++;
	return p;
}