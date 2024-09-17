#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int MAX_STATES = 16; // 状态的最大数量
const int MOD = 998244353; // 取模数

// 定义状态和逻辑门
struct LogicGate {
    int a, b, c;
};

// 启发式函数
int heuristic(int currentState, int targetState) {
    int h = 0;
    for (int i = 0; i < MAX_STATES; ++i) {
        if ((targetState & (1 << i)) && !(currentState & (1 << i))) {
            h++;
        }
    }
    return h;
}

// 使用A*寻找最小逻辑门代价
pair<int, int> a_star(int initialState, const vector<LogicGate>& gates, int targetState, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> distance;
    unordered_map<int, int> ways;
    unordered_set<int> visited;

    pq.push({ heuristic(initialState, targetState), initialState });
    distance[initialState] = 0;
    ways[initialState] = 1;

    while (!pq.empty()) {
        auto current = pq.top();
        int currentState = current.second;
        pq.pop();

        if (visited.find(currentState) != visited.end()) {
            continue;
        }
        visited.insert(currentState);

        int currentCost = distance[currentState];

        if ((currentState & targetState) == targetState) {
            return { currentCost, ways[currentState] };
        }

        for (const auto& gate : gates) {
            if ((currentState & (1 << gate.a)) && (currentState & (1 << gate.b)) && !(currentState & (1 << gate.c))) {
                int nextState = currentState | (1 << gate.c);
                int newCost = currentCost + 1;
                if (distance.find(nextState) == distance.end() || newCost < distance[nextState]) {
                    distance[nextState] = newCost;
                    ways[nextState] = ways[currentState];
                    pq.push({ newCost + heuristic(nextState, targetState), nextState });
                }
                else if (newCost == distance[nextState]) {
                    ways[nextState] = (ways[nextState] + ways[currentState]) % MOD;
                }
            }
        }
    }

    return { -1, 0 }; // 如果无法达到目标状态
}

int main() {
    int n, m, s_size;
    cin >> n >> m >> s_size;

    int initialState = 0;
    for (int i = 0; i < s_size; ++i) {
        int state;
        cin >> state;
        initialState |= (1 << state);
    }

    vector<LogicGate> gates(m);
    for (int i = 0; i < m; ++i) {
        cin >> gates[i].a >> gates[i].b >> gates[i].c;
    }

    int q;
    cin >> q;

    while (q--) {
        int t_size;
        cin >> t_size;

        int targetState = 0;
        for (int i = 0; i < t_size; ++i) {
            int state;
            cin >> state;
            targetState |= (1 << state);
        }

        pair<int, int> result = a_star(initialState, gates, targetState, n);
        cout << result.first << endl;
    }

    return 0;
}
