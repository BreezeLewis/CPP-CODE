#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
////n 个元素的集合划分到 k 个盒子里
////边界
//// k==0 || n==0 return 0
//// k==1 return 1
//// n==k return 1
////递归关系式
////情况1：a[i]是k个子集中的一个，其余n-1放到k-1中
//// f(n-1,k-1)
////情况2：a[i]不是k个子集中的一个，其余n-1个元素划分到k个盒子里
//// 并且a[i]与k个集合中的任意一个可以构成一个新的集合
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