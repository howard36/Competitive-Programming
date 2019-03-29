#include <bits/stdc++.h>
#define ll long long

int main() {
    int n;
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i<n; i++){
        ans += i*(n-i);
    }
    ans += n;
    printf("%lld", ans);
}