#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    int a, b;
    scanf("%d", &a);
    int ans = 0;
    for (int i = 1; i<n; i++){
        scanf("%d", &b);
        if (a + b == 5){
            printf("Infinite");
            return 0;
        }
        ans += a + b;
        a = b;
    }
    printf("Finite\n");
    printf("%d", ans);
}