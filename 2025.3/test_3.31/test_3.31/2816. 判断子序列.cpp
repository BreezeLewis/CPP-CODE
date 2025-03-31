#include <iostream>

using namespace std;

const int N = (int)1e5 + 10;

int a[N], b[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    for (; i < n && j < m;)
    {
        if (a[i] == b[j]) i++;
        j++;
    }

    if (i == n) printf("Yes\n");
    else printf("No\n");

    return 0;
}