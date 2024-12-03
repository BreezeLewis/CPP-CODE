#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 5e5 + 10;
const int char_size = 26;
int nxt[maxn + 1][char_size];
bool isend[maxn + 1];
int cnt = 0;

void insert(char s[], int len) {
    int now = 0;
    for (int i = 0; i < len; i++) {
        int x = s[i] - 'a';
        if (!nxt[now][x])
            nxt[now][x] = ++cnt;
        now = nxt[now][x];
    }
    isend[now] = 1;
}

bool search(char s[], int len) {
    int now = 0;
    for (int i = 0; i < len; i++) {
        int x = s[i] - 'a';
        if (!nxt[now][x])
            return false;
        now = nxt[now][x];
    }
    return isend[now];
}

int main() {
    int n, m;
    scanf("%d", &n);
    char str[11];
    while (n--) {
        scanf("%s", str);
        insert(str, strlen(str));
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%s", str);
        printf("%d\n", search(str, strlen(str)));
    }
}