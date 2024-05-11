#include <iostream>

using namespace std;

const int N = 100010;

int a[N], q[N];

int main()
{
    int n, len = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    q[0] = -2e9;

    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }

    cout << len << endl;

    return 0;
}