#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first > y.first;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int reward1[1010] = { 0 };
    int reward2[1010] = { 0 };
    vector<pair<int, int>> v(1010);
    for (int i = 0; i < n; i++)
        cin >> reward1[i];

    for (int i = 0; i < n; i++)
        cin >> reward2[i];

    for (int i = 0; i < n; i++)
    {
        v[i].first = reward1[i] - reward2[i];
        v[i].second = i;
    }
    sort(v.begin(), v.begin() + n, cmp);
    int res = 0;
    int i = 0;
    while (k--)
    {
        res += reward1[v[i++].second];
    }
    while (i < n)
    {
        res += reward2[v[i++].second];
    }
    cout << res << endl;
    return 0;
}