<<<<<<< HEAD
//#include <stdio.h>
//int main()
//{
//	int n = 1010;
//	float* pFloat = (float*)&n;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	*pFloat = 1010.0;
//	printf("num��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	return 0;
//}

#include <stdio.h>
union u
{
	int a, b;
	float c;
}vu;
int main()
{
	vu.a = 1;
	vu.b = 2;
	vu.c = 3;
	return 0;
}














=======
//#include <stdio.h>
//int main()
//{
//	int n = 1010;
//	float* pFloat = (float*)&n;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	*pFloat = 1010.0;
//	printf("num��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	return 0;
//}

#include <stdio.h>
union u
{
	int a, b;
	float c;
}vu;
int main()
{
	vu.a = 1;
	vu.b = 2;
	vu.c = 3;
	return 0;
}














>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
