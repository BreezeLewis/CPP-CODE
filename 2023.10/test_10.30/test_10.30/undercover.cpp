#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
    int n, m, p, i, x[100], count = 0, num = 0;  // x 数组是每个玩家的回答 
    int a[100] = { 0 }, sum[100] = { 0 };             // count 是每轮说真话统计数 
    cout << "Enter gamers(n) & say truth(m): ";  // num 符合题意的次数
    cin >> n >> m;                               // a 数组是每轮每个玩家说真话 1，说假话 0 
    cout << "Enter a Line answers: ";            // sum 数组是符合题意的每个玩家说真话次数，若全真话 num 
    for (i = 1; i <= n; i++)                        //     全假话 0，有些真有些假则 0~num 之间 
        cin >> x[i];
    for (p = 1; p <= n; p++)                            // p 是卧底者（若是 1,2,3,......n,进行测试） 
    {
        count = 0;
        for (i = 1; i <= n; i++)
        {
            a[i] = 0;
            if ((x[i] > 0 && x[i] == p) || (x[i] < 0 && (-x[i]) != p))  // 说真话统计 
            {
                a[i] += 1;
                count++;
            }
        }
        if (count == m)                           // 符合题意的，进行累加统计 
        {
            num++;
            for (i = 1; i <= n; i++)
                sum[i] += a[i];
        }
    }
    cout << "-------------------------------------" << endl;
    for (i = 1; i <= n; i++)                           // 输出，全真，全假，有真有假 
    {
        if (sum[i] == num && num > 0)
            cout << "Truth" << endl;
        else if (sum[i] == 0 && num > 0)
            cout << "Lie" << endl;
        else
            cout << "Not defined" << endl;
    }
}
