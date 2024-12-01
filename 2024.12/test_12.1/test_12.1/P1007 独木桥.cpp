#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int sizes = 5005;
int a[sizes];
int main()
{
    int L, N;
    cin >> L >> N;
    if (!N) //特判 N==0的情况 
    {
        cout << "0 0" << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++) cin >> a[i]; //输入
    sort(a + 1, a + N + 1); //从小到大排序（算最长时间时可能方便一些）
    int max_time, min_time;
    for (int i = 1; i <= N; i++)
        min_time = max(min(a[i], L + 1 - a[i]), min_time); //最短时间就是所有人中走完桥最小值中的最大值 
    max_time = max(L + 1 - a[1], a[N]); //最长时间就是最靠近端点两个人各自向对方走,
    //时间较长的那个人的时间 （排序的好处）
    cout << min_time << ' ' << max_time << endl;
    return 0;
}