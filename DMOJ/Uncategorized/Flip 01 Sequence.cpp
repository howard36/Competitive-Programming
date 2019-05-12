#include <bits/stdc++.h>

int a[2000006];

int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i<n; i++){
        char c;
        scanf(" %c", &c);
        a[i] = c-'0';
    }
}