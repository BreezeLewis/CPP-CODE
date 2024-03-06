#include <iostream>

using namespace std;

const int N = 100010;

int n, q[N], hh, tt = -1;

void push(int x)
{
    q[++tt] = x;
}

void pop()
{
    ++hh;
}

void empty()
{
    if (hh <= tt) cout << "NO" << endl;
    else cout << "YES" << endl;
}

void query()
{
    cout << q[hh] << endl;
}

int main()
{
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (str == "pop") pop();
        else if (str == "empty") empty();
        else query();
    }

    return 0;
}