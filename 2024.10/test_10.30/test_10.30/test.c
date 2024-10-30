//#define _CRT_SECURE_NO_WARNINGS
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void func(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//int main()
//{
//	char* p = NULL;
//
//	func(p);
//
//	strcpy(p, "hello\n");
//
//	return 0;
//
//}

#include <stdio.h>
#include <string.h>

int main()
{
	int n = 0;

	n = (n++) + (++n) - (--n);

	printf("%d", n);
}