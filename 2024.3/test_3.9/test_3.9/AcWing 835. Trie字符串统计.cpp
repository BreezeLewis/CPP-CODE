#include <iostream>

using namespace std;

const int N = 100010;

int n;
int son[N][26], idx, cnt[N];
char str[N];

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    cin >> n;
    while (n--)
    {
        char op;
        cin >> op >> str;
        if (op == 'I')
            insert(str);
        else if (op == 'Q')
            cout << query(str) << endl;
    }

    return 0;
}