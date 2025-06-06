#include <iostream>

using namespace std;

const int N = (int)1e6 + 10;

int a[N];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    while (k--)
    {
        int x;
        cin >> x;

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid] >= x) r = mid;
            else l = mid + 1;
        }

        if (a[l] == x)
            cout << l << ' ';
        else
        {
            cout << -1 << ' ' << -1 << endl;
            continue;
        }

        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (a[mid] <= x) l = mid;
            else r = mid - 1;
        }
        cout << r << endl;
    }

    return 0;
}