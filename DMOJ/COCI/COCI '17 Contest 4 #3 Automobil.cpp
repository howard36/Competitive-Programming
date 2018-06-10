#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

ll r[1000006], c[1000006];

int main() {
    freopen("data.txt", "r", stdin);
    int n, m, k, x, y;
    char chr;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i<=n; i++){
        r[i] = 1;
    }
    for (int i = 1; i<=m; i++){
        c[i] = 1;
    }
    for (int i = 0; i<k; i++){
        scanf(" %c%d%d", &chr, &x, &y);
        if (chr == 'R'){
            r[x] = r[x]*y%mod;
        }
        else{
            c[x] = c[x]*y%mod;
        }
    }
    ll sum = 0, Rsum = 0, Csum = 0;
    for (int i = 1; i<=n; i++){
        Rsum = (Rsum+r[i])%mod;
    }
    for (int i = 1; i<=m; i++){
        Csum = (Csum+c[i])%mod;
    }
    for (int i = 0; i<n; i++){
        sum += i*r[i+1]%mod;
        sum %= mod;
    }
    sum *= m*Csum%mod;
    sum %= mod;
    ll ans = sum;
    sum = 0;
    for (int j = 1; j<=m; j++){
        sum += j*c[j]%mod;
        sum %= mod;
    }
    ans += (Rsum*sum)%mod;
    ans %= mod;
    printf("%lld", ans);
}
