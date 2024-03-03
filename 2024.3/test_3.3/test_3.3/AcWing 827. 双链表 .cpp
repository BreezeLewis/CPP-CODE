#include <iostream>

using namespace std;

const int N = 100010;

int n, e[N], l[N], r[N], idx;

void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void add(int k, int x)//在k节点的右边插入
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx++;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    init();

    cin >> n;
    while (n--)
    {
        string op;
        cin >> op;
        int k, x;
        if (op[0] == 'R')
        {
            cin >> x;
            add(l[1], x);
        }
        else if (op[0] == 'L')
        {
            cin >> x;
            add(0, x);
        }
        else if (op[0] == 'D')
        {
            cin >> k;
            remove(k + 1);
        }
        else if (op[0] == 'I')
        {
            cin >> k >> x;
            if (op[1] == 'L')
                add(l[k + 1], x);
            else
                add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";

    return 0;
}

