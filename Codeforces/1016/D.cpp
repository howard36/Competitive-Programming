#include <bits/stdc++.h>
using namespace std;

int a[102], b[102];

int main() {
    // freopen("data.txt", "r", stdin);
    int n, m, x = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        x ^= a[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        x ^= b[i];
    }
    if (x != 0) {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for (int i = 0; i < m - 1; i++) {
        printf("%d ", b[i]);
        x ^= b[i];
    }
    printf("%d\n", x ^ a[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 1; j++)
            printf("0 ");
        printf("%d\n", a[i]);
    }
}