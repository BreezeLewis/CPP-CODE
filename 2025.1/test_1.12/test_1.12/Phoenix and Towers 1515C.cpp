#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    // Store heights with their original indices
    vector<pair<int, int>> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i].first;
        h[i].second = i;
    }

    // Sort blocks by height
    sort(h.begin(), h.end());

    // Assign blocks to towers in round-robin fashion
    vector<int> ans(n);
    int curr_tower = 0;

    for (int i = 0; i < n; i++) {
        ans[h[i].second] = curr_tower + 1;
        curr_tower = (curr_tower + 1) % m;
    }

    // Check if construction is possible
    vector<long long> tower_heights(m, 0);
    for (int i = 0; i < n; i++) {
        tower_heights[(ans[i] - 1)] += h[i].first;
    }

    long long min_height = *min_element(tower_heights.begin(), tower_heights.end());
    long long max_height = *max_element(tower_heights.begin(), tower_heights.end());

    if (max_height - min_height > x) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}