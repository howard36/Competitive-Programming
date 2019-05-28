#include <bits/stdc++.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int d = (n-k)/2 + 1;
    for (int i = 0; i<n; i++) {
        if (i%d)
            printf("1");
        else
            printf("0");
    }
}