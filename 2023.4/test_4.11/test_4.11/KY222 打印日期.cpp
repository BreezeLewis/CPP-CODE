//#include <iostream>
//using namespace std;
//int main()
//{
//    int y, n;
//    while (cin >> y >> n)
//    {
//        int monthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//            monthDay[2]++;
//        int sum = 0, i = 1, m = n;
//        while (sum + monthDay[i] < m)
//        {
//            sum += monthDay[i];
//            n -= monthDay[i++];
//        }
//
//        printf("%04d-%02d-%02d\n", y, i, n);
//    }
//    return 0;
//}