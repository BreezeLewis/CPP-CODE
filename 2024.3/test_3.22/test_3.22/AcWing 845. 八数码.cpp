#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

string start;

int bfs()
{
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;
    d[start] = 0;
    q.push(start);

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int distance = d[t];
        if (t == end) return distance;

        int k = t.find('x');
        int x = k / 3, y = k % 3;

        int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];

            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[k], t[a * 3 + b]);

                if (!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }

                swap(t[k], t[a * 3 + b]);
            }
        }
    }

    return -1;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
    }

    cout << bfs() << endl;

    return 0;
}