#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    bool operator<(const Range& W)const
    {
        return r < W.r;
    }
}range[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = { l, r };
    }

    sort(range, range + n);

    int res = 0, ed = -2e9;
    for (int i = 0; i < n; i++)
        if (range[i].l > ed)
        {
            res++;
            ed = range[i].r;
        }

    cout << res << endl;

    return 0;
}