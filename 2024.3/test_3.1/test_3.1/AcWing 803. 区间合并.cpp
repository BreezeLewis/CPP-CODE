#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
typedef pair<int, int> PII;

const int N = 100010;

vector<PII> segs;

void merge(vector<PII>& segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (const auto& seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({ st, ed });
            st = seg.first, ed = seg.second;
        }
        else
            ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({ st, ed });

    segs = res;

}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({ l, r });
    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}