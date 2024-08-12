#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

#include <vector>

using namespace std;

int f(string state)
{
    int res = 0;
    for (int i = 0; i < state.size(); i++)
        if (state[i] != 'x')
        {
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }

    return res;
}

string bfs(string start)
{
    int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
    char op[] = { 'u', 'r', 'd', 'l' };

    string end = "12345678x";
    unordered_map<string, int> dist;
    unordered_map<string, pair<string, char>> prev;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> heap;

    heap.push({ f(start), start });
    dist[start] = 0;

    while (heap.size())
    {
        pair<int, string> t = heap.top();
        heap.pop();

        string state = t.second;
        if (state == end) break;

        int step = dist[state];
        int x, y;
        for (int i = 0; i < state.size(); i++)
            if (state[i] == 'x')
            {
                x = i / 3, y = i % 3;
                break;
            }
        string source = state;

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;

            swap(state[x * 3 + y], state[a * 3 + b]);
            if (!dist.count(state) || dist[state] > step + 1)
            {
                dist[state] = step + 1;
                prev[state] = { source, op[i] };
                heap.push({ dist[state] + f(state), state });
            }
            swap(state[x * 3 + y], state[a * 3 + b]);
        }
    }

    string res;

    while (end != start)
    {
        res += prev[end].second;
        end = prev[end].first;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string start, seq;
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
        if (c != 'x') seq += c;
    }

    int cnt = 0;
    for (int i = 0; i < 8; i++)
        for (int j = i; j < 8; j++)
            if (seq[i] > seq[j])
                cnt++;

    if (cnt & 1) puts("unsolvable");
    else cout << bfs(start) << endl;

    return 0;
}