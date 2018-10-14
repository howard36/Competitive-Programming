#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[500005];

int main() {
    int n;
    ll m, sum = 0;
    scanf("%d %lld", &n, &m);
    for (int i = 0; i<n; i++){
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (sum < m){
        printf("-1");
        return 0;
    }
    int r = 0, best = 1e9;
    ll s = 0;
    for (int l = 0; l<n; l++){
        while (s < m){
            if (r == n){
                printf("%d", best);
                return 0;
            }
            s += a[r];
            r++;
        }
        best = min(best, r-l);
        s -= a[l];
    }
    printf("%d", best);
    return 0;
}
