#include <bits/stdc++.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (m == 0){
        printf("1");
    }
    else if (m <= n/2){
        printf("%d", m);
    }
    else {
        printf("%d", n-m);
    }
}