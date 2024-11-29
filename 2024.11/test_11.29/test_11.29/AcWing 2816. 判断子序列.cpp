#include <iostream>

using namespace std;

const int N = (int)1e5 + 10;

int a[N], b[N];
int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    int i = 0, j = 0;

    for (; i < n && j < m;)
    {
        if (a[i] == b[j]) i++;
        j++;
    }

    cout << (i == n ? "Yes" : "No") << endl;

    return 0;
}