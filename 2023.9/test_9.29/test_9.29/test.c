#include <stdio.h>
int even(int n)
{
	return n % 2 == 0;
}
int OddSum(int List[], int N)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
		if (!even(List[i]))
			sum += List[i];
	return sum;
}

int main()
{
	int a[] = { 10,20,30,40,50,60,70,80,90,100 };
	int size = sizeof(a) / sizeof(int);
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
	printf("所有奇数的和为%d\n", OddSum(a, size));

	return 0;
}