#include <iostream>

using namespace std;

const int N = 100010;

int n, m, h[N], sz;

void down(int x)
{
    int t = x;
    if (2 * x <= sz && h[2 * x] < h[t]) t = 2 * x;
    if (2 * x + 1 <= sz && h[2 * x + 1] < h[t]) t = 2 * x + 1;
    if (x != t)
    {
        swap(h[x], h[t]);
        down(t);
    }
}

void adjust_down(int p)
{
    int c = 2 * p;
    while (c <= sz)
    {
        if (c + 1 <= sz && h[c + 1] < h[c]) c++;
        if (h[c] < h[p])
        {
            swap(h[c], h[p]);
            p = c;
            c = 2 * p;
        }
        else break;
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> h[i];
    sz = n;

    for (int i = n / 2; i; i--) adjust_down(i);

    while (m--)
    {
        cout << h[1] << " ";
        h[1] = h[sz--];
        adjust_down(1);
        //adjust_down
    }

    return 0;
}