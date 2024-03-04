#include <iostream>

using namespace std;

int n;
const int N = 100010;

int tt, stk[N];

void push(int x)
{
    stk[++tt] = x;
}

void pop()
{
    --tt;
}

void empty()
{
    if (tt) cout << "NO" << endl;
    else cout << "YES" << endl;
}

void  query()
{
    cout << stk[tt] << endl;
}

int main()
{
    cin >> n;
    while (n--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (op == "pop")
            pop();
        else if (op == "empty")
            empty();
        else
            query();
    }

    return 0;
}

