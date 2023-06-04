//#include <iostream>
//#include <cmath>
//using namespace std;
//int a[7];
//int main()
//{
//	while (1)
//	{
//		int cnt = 0, ans = 0, num2 = 0, num1 = 0;
//		for (int i = 1; i <= 6; i++)
//		{
//			cin >> a[i];
//			if (!a[i]) 
//				cnt++;
//		}
//		if (cnt == 6)
//			break;
//		ans = a[6] + a[5] + a[4] + (int)ceil(a[3] / 4.0);
//		int ret = 0;//记录装3*3的箱子剩余多少2*2的位置
//		if (a[3] % 4)
//			ret = 5 - (a[3] % 4 - 1) * 2;
//		
//		num2 = 5 * a[4] + ret;//剩多少个格子装2*2
//		if (a[2] > num2)
//			ans += (int)ceil((a[2] - num2) / 9.0);
//		num1 = ans * 36 - a[6] * 36 - a[5] * 25 - a[4] * 16 - a[3] * 9 - a[2] * 4;
//		if (a[1] > num1)
//			ans += (int)ceil((a[1] - num1) / 36.0);
//		cout << ans << endl;
//	}
//	return 0;
//}