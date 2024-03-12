#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int N = 100010;
int n, m, size[N], p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        size[i] = 1;
    }
    while (m--)
    {
        string op;
        cin >> op;
        int a, b;
        if (op[0] == 'C')
        {
            cin >> a >> b;
            if (find(a) == find(b)) continue;
            size[find(b)] += size[find(a)];
            p[find(a)] = find(b);
        }
        else if (op[1] == '1')
        {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else
        {
            cin >> a;
            cout << size[find(a)] << endl;
        }
    }

    return 0;
}