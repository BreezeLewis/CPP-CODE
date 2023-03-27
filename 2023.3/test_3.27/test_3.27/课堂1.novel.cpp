#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Novel.h"
int main()
{
	Novel n1("hello", "world");
	n1 = n1;
	cout << n1;
	Novel n2 = n1;
	cout << n2;
	Novel n3(n2);
	cout << n3;
	return 0;
}