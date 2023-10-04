#include <iostream>
using namespace std;
void insertStr(char mainStr[], char subStr[], int pos)
{
	int lenMain = (int)strlen(mainStr);
	int lenSub = (int)strlen(subStr);
	for (int i = pos; i < lenMain; i++)
	{
		mainStr[i + lenSub] = mainStr[i];
	}

	for (int i = pos; i < pos + lenSub; i++)
	{
		mainStr[i] = subStr[i - pos];
	}
}
int main()
{
	char mainStr[100] = "Hello world";
	char subStr[] = "My name is ZhangSan";
	int pos = 5;

	insertStr(mainStr, subStr, pos);

	cout << mainStr << endl;

	return 0;
}