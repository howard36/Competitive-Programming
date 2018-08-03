#include <bits/stdc++.h>
using namespace std;

int s[1003], t[1003], a[1003], pre[1003];
int n, m, q;

int isSubstring(int x) {
    for (int i = 0; i < m; i++) {
        if (t[i] != s[x + i])
            return 0;
    }
    return 1;
}

int main() {
    char c;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c);
        s[i] = c - 'a';
    }
    for (int i = 0; i < m; i++) {
        scanf(" %c", &c);
        t[i] = c - 'a';
    }
    for (int i = 1; i <= n - m + 1; i++) {
        a[i] = isSubstring(i);
        pre[i] = a[i] + pre[i - 1];
    }
    int l, r;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        r -= m - 1;
        if (l > r) {
            printf("0\n");
        } else {
            printf("%d\n", pre[r] - pre[l - 1]);
        }
    }
}