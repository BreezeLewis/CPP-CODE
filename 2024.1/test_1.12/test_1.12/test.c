#include <stdio.h>

#pragma pack(3)

struct node
{
	short a;
	short b;
};

int main()
{
	struct node n;

	printf("%d\n", sizeof(n));;

	return 0;
}