#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
////n ��Ԫ�صļ��ϻ��ֵ� k ��������
////�߽�
//// k==0 || n==0 return 0
//// k==1 return 1
//// n==k return 1
////�ݹ��ϵʽ
////���1��a[i]��k���Ӽ��е�һ��������n-1�ŵ�k-1��
//// f(n-1,k-1)
////���2��a[i]����k���Ӽ��е�һ��������n-1��Ԫ�ػ��ֵ�k��������
//// ����a[i]��k�������е�����һ�����Թ���һ���µļ���
//// f(n-1,k)*k
////f(n,k)=f(n-1,k-1) + k*f(n-1,k)
//int n, k, res;
//long long f(int n, int k)
//{
//	if (k == 0 || n == 0)
//		return 0;
//	if (k == 1 || n == k)
//		return 1;
//	return f(n - 1, k - 1) + k * f(n - 1, k);
//}
//int main()
//{
//	scanf("%d%d", &n, &k);
//	printf("%lld\n", f(n, k));
//	return 0;
//}