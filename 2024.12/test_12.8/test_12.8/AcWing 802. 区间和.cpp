#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = (int)3e5 + 10;

int n, m;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;

int find(int x)
{
    int l = 0, r = (int)alls.size() - 1;

    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return r;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back(make_pair(x, c));
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back(make_pair(l, r));

        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());

    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 0; i < alls.size(); i++) s[i] = s[i - 1] + a[i];

    for (auto item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;

}
