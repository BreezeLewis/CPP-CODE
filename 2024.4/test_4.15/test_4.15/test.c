#include <stdio.h>

int main()
{
	double data[1000] = { 0 };

	printf("sizeof(double) = %ld\n", sizeof(double));
	printf("address of data is %p\n", data);

	for (int i = 0; i < 10000; i++)
	{
		printf("data[%d] = %f, addr = %p\n", i, data[i], &data[i]);
	}

	printf("success!\n");

	return 0;
}