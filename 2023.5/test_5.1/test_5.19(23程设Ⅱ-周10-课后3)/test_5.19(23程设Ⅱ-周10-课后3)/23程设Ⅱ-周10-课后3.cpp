#include <iostream>
using namespace std;
const int N = 100010;
int tt;
struct node
{
    int value;
    int pos;
}a[N], b[N], stk[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].value, a[i].pos = i;
    for (int i = n - 1; i >= 0; i--)
    {
        while (tt && stk[tt].value <= a[i].value) tt--;
        if (tt) b[i] = stk[tt];
        else b[i].value = 0;
        stk[++tt] = a[i];
    }
    for (int i = 0; i < n; i++) cout << b[i].value << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (b[i].pos)
            cout << b[i].pos - i << endl;
        else
            cout << b[i].pos << endl;
    }

    return 0;
}
