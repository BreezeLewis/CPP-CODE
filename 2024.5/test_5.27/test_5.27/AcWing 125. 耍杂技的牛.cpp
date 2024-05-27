#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 50010;

int n;
PII cows[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w, s;
        cin >> w >> s;
        cows[i] = { w + s, w };
    }

    sort(cows, cows + n);

    int sum = 0, res = -2e9;

    for (int i = 0; i < n; i++)
    {
        int w = cows[i].second, s = cows[i].first - w;
        res = max(res, sum - s);
        sum += w;
    }

    cout << res;

    return 0;
}