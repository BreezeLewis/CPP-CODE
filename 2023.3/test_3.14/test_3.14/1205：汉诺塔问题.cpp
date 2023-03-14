//#include<iostream>
//using namespace std;
////此题C语言效率远高于CPP
//void hanoi(int n,char src,char via,char dst)/*把n个柱子从a柱，借助b柱移到c柱上*/
//{
//	if (n == 1)
//	{
//		//cout << src << "->" << n << "->" << dst << endl;
//		printf("%c->%d->%c\n", src, n, dst);
//		return;
//	}
//	hanoi(n - 1, src, dst, via);
//	//cout << src << "->" << n << "->" << dst << endl;
//	printf("%c->%d->%c\n", src, n, dst);
//	hanoi(n - 1, via, src, dst);
//}
//int main()
//{
//	int n;
//	char a, b, c;
//	cin >> n >> a >> b >> c;
//	hanoi(n, a, c, b);
//	return 0;
//}