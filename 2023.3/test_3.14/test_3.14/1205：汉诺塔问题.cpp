//#include<iostream>
//using namespace std;
////����C����Ч��Զ����CPP
//void hanoi(int n,char src,char via,char dst)/*��n�����Ӵ�a��������b���Ƶ�c����*/
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