#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;

string move(string x, int op)
{
    string t;
    if (op == 0) return t + x[7] + x[6] + x[5] + x[4] + x[3] + x[2] + x[1] + x[0];
    if (op == 1) return t + x[3] + x[0] + x[1] + x[2] + x[5] + x[6] + x[7] + x[4];
    if (op == 2) return t + x[0] + x[6] + x[1] + x[3] + x[4] + x[2] + x[5] + x[7];
    return t;
}

int bfs(string start, string end)
{
    queue<string> q;
    q.push(start);
    dist[start] = 0;

    while (q.size())
    {
        string t = q.front();
        q.pop();
        if (t == end) return dist[t];
        for (int i = 0; i < 3; i++)
        {
            string x = move(t, i);
            //if (dist.count(x)) continue;
            //if (x == end) return dist[t] + 1;
            if (!dist.count(x))
            {
                dist[x] = dist[t] + 1;
                pre[x] = { i + 'A', t };
                q.push(x);
            }
        }
    }

    return -1;
}

int main()
{
    string start, end;
    start = "12345678";

    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        end += x + '0';
    }

    cout << bfs(start, end) << endl;

    string res;

    while (end != start)
    {
        res += pre[end].first;
        end = pre[end].second;
    }

    reverse(res.begin(), res.end());

    cout << res;

    return 0;
}