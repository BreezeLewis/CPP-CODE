#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, k, x, sz, idx;
int h[N], hp[N], ph[N];
string op;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int p)
{
    int t = p;
    if (2 * p <= sz && h[2 * p] < h[t]) t = 2 * p;
    if (2 * p + 1 <= sz && h[2 * p + 1] < h[t]) t = 2 * p + 1;
    if (p != t)
    {
        heap_swap(p, t);
        down(t);
    }
}

void adjust_down(int p)
{

}

void up(int c)
{
    while (c / 2 && h[c / 2] > h[c])
    {
        heap_swap(c / 2, c);
        c /= 2;
    }
}

void adjust_up(int c)
{

}

int main()
{
    cin >> n;

    while (n--)
    {
        cin >> op;
        if (op == "I")//I x，插入一个数 x
        {
            cin >> x;
            idx++, sz++;
            ph[idx] = sz, hp[sz] = idx;
            h[sz] = x;
            up(sz);
        }
        else if (op == "PM")//PM,输出当前集合中的最小值
            cout << h[1] << endl;
        else if (op == "DM")//DM，删除当前集合中的最小值
        {
            heap_swap(1, sz--);
            down(1);
        }
        else if (op == "D")//D k，删除第k个插入的数
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, sz--);
            down(k), up(k);
        }
        else if (op == "C")//C k x，修改第k个插入的数，将其变为 x
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }

    return 0;
}