#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    bool operator<(const Range& W)const
    {
        return l < W.l;
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

    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < n; i++)
    {
        if (heap.empty() || heap.top() >= range[i].l) heap.push(range[i].r);
        else
        {
            heap.pop();
            heap.push(range[i].r);
        }
    }

    cout << heap.size() << endl;

    return 0;
}