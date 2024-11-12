#include <iostream>
using namespace std;

int s[5001];
int n, m, p;

void init() {
    for (int i = 1; i <= n; i++)
        s[i] = i;
}

int find_set(int x) {
    return x == s[x] ? x : find_set(s[x]);
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x != y) s[x] = s[y];
}

int main() {
    cin >> n >> m >> p;
    init();
    int a, b;
    while (m--) {
        cin >> a >> b;
        union_set(a, b);
    }
    while (p--) {
        cin >> a >> b;
        if (find_set(a) == find_set(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}