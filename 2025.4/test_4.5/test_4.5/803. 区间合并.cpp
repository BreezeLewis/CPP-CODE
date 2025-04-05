#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

vector<PII> a;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        a.push_back({ l, r });
    }

    sort(a.begin(), a.end());

    int st = a[0].first, ed = a[0].second;
    int res = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i].first <= ed) ed = max(a[i].second, ed);
        else res++, st = a[i].first, ed = a[i].second;
    }
    cout << res << endl;

    return 0;

}