#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
    int n, m, p, i, x[100], count = 0, num = 0;  // x ������ÿ����ҵĻش� 
    int a[100] = { 0 }, sum[100] = { 0 };             // count ��ÿ��˵�滰ͳ���� 
    cout << "Enter gamers(n) & say truth(m): ";  // num ��������Ĵ���
    cin >> n >> m;                               // a ������ÿ��ÿ�����˵�滰 1��˵�ٻ� 0 
    cout << "Enter a Line answers: ";            // sum �����Ƿ��������ÿ�����˵�滰��������ȫ�滰 num 
    for (i = 1; i <= n; i++)                        //     ȫ�ٻ� 0����Щ����Щ���� 0~num ֮�� 
        cin >> x[i];
    for (p = 1; p <= n; p++)                            // p ���Ե��ߣ����� 1,2,3,......n,���в��ԣ� 
    {
        count = 0;
        for (i = 1; i <= n; i++)
        {
            a[i] = 0;
            if ((x[i] > 0 && x[i] == p) || (x[i] < 0 && (-x[i]) != p))  // ˵�滰ͳ�� 
            {
                a[i] += 1;
                count++;
            }
        }
        if (count == m)                           // ��������ģ������ۼ�ͳ�� 
        {
            num++;
            for (i = 1; i <= n; i++)
                sum[i] += a[i];
        }
    }
    cout << "-------------------------------------" << endl;
    for (i = 1; i <= n; i++)                           // �����ȫ�棬ȫ�٣������м� 
    {
        if (sum[i] == num && num > 0)
            cout << "Truth" << endl;
        else if (sum[i] == 0 && num > 0)
            cout << "Lie" << endl;
        else
            cout << "Not defined" << endl;
    }
}
