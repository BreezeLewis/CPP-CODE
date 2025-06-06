#include <iostream>

using namespace std;

const int N = 100010;
int n, e[N], ne[N], idx, head;

void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    init();
    cin >> n;
    while (n--)
    {
        char op;
        int k, x;
        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (k == 0) head = ne[head];
            else remove(k - 1);
        }
        else if (op == 'I')
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";
    cout << endl;

    return 0;
}

