#include <bits/stdc++.h>
#define ll long long

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll l, r, g;
        scanf("%lld %lld %lld", &l, &r, &g);
        ll ans = r/g - (l+g-1)/g + 1;
        if (ans == 1 && (l > g || r < g))
            ans = 0;
        printf("%lld\n", ans);
    }
}