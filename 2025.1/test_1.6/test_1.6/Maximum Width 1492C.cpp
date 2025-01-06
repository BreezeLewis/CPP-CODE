#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    vector<int> leftmost(m), rightmost(m);

    // Find leftmost possible positions
    int pos = 0;
    for (int i = 0; i < m; i++) {
        while (pos < n && s[pos] != t[i]) {
            pos++;
        }
        leftmost[i] = pos;
        pos++;
    }

    // Find rightmost possible positions
    pos = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (pos >= 0 && s[pos] != t[i]) {
            pos--;
        }
        rightmost[i] = pos;
        pos--;
    }

    // Find maximum width
    int max_width = 0;
    for (int i = 0; i < m - 1; i++) {
        max_width = max(max_width, rightmost[i + 1] - leftmost[i]);
    }

    cout << max_width << "\n";

    return 0;
}