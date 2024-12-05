#include <iostream>
#include <string>
using namespace std;

string p, s;
int nxt[1000010];

int main() {
    cin >> s >> p;

    nxt[0] = nxt[1] = 0;
    int j = 0;
    for (int i = 1; i < p.size(); i++) {
        while (j && p[i] != p[j]) j = nxt[j];
        nxt[i + 1] = (p[i] == p[j] ? ++j : 0);
    }

    j = 0;
    for (int i = 0; i < s.size(); i++) {
        while (j && s[i] != p[j]) j = nxt[j];
        j += (s[i] == p[j] ? 1 : 0);
        if (j == p.size()) {
            printf("%d\n", i - p.size() + 2);
        }
    }

    for (int i = 1; i <= p.size(); i++) {
        printf("%d ", nxt[i]);
    }
}