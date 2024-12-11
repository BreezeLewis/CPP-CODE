    #include <iostream>
    #include <vector>
    #include <unordered_set>
    using namespace std;
    typedef long long ll;

    const int MOD = 1000000007;

    struct UnionFind {
        vector<int> parent;
        UnionFind(int n) : parent(n + 1) { 
            for (int i = 0; i <= n; ++i) parent[i] = i;
        }
        int find_set(int x) {
            if (parent[x] != x)
                parent[x] = find_set(parent[x]);
            return parent[x];
        }
        void union_set(int x, int y) {
            int fx = find_set(x);
            int fy = find_set(y);
            if (fx != fy)
                parent[fy] = fx;
        }
    };

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        UnionFind uf(n);

        vector<bool> used(n + 1, false);

        int self_loops = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                self_loops += 1;
            }
            else {
                uf.union_set(a[i], b[i]);
                used[a[i]] = true;
                used[b[i]] = true;
            }
        }

        unordered_set<int> roots;
        for (int k = 1; k <= n; ++k) {
            if (used[k]) {
                roots.insert(uf.find_set(k));
            }
        }

        int cycles = (int)roots.size() + self_loops;

        ll answer = 1;
        for (int i = 0; i < cycles; ++i) {
            answer = (answer * 2) % MOD;
        }

        cout << answer;
    }
