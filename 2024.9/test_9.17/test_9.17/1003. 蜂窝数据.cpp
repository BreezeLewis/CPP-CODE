#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MOD 998244353

using namespace std;

struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

vector<Point> directions = {
    Point(2, 0), Point(1, 1), Point(-1, 1),
    Point(-2, 0), Point(-1, -1), Point(1, -1)
};

int main() {
    int t;
    cin >> t;
    vector<Point> targets;

    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        targets.push_back(Point(a, b));
    }

    map<Point, int> min_time;
    map<Point, int> ways;
    queue<Point> q;

    Point origin(0, 0);
    q.push(origin);
    min_time[origin] = 0;
    ways[origin] = 1;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        int curr_time = min_time[curr];
        int curr_ways = ways[curr];

        for (Point dir : directions) {
            Point next(curr.x + dir.x, curr.y + dir.y);
            if (min_time.find(next) == min_time.end()) {
                min_time[next] = curr_time + 1;
                ways[next] = curr_ways;
                q.push(next);
            }
            else if (min_time[next] == curr_time + 1) {
                ways[next] = (ways[next] + curr_ways) % MOD;
            }
        }
    }

    for (Point target : targets) {
        cout << min_time[target] << " " << ways[target] << endl;
    }

    return 0;
}
