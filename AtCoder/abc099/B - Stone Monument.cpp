#include <bits/stdc++.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int d = b-a;
    printf("%d", d*(d-1)/2 - a);
}
