#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
        a[i] = abs(a[i]);
    }
    sort(a, a+n);
    long long ans = 0;
    for (int i = 0; i<n; i++){
        ans += upper_bound(a, a+n, 2*a[i]) - lower_bound(a, a+n, (a[i]+1)/2) - 1;
        // printf("i = %d, a[i] = %d, ans = %lld\n", i, a[i], ans);
    }
    printf("%lld", ans/2);
}