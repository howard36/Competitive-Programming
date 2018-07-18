#include <bits/stdc++.h>

int main() {
    int a, b, c, n;
    scanf("%d%d%d%d", &a, &b, &c, &n);
    int x = n-a-b+c;
    if (x <= 0 || c > a || c > b){
        printf("-1");
    }
    else
        printf("%d", x);
}
