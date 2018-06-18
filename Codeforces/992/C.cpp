#include <bits/stdc++.h>
#define mod 1000000007LL
#define ll long long

int main() {
    ll x, k;
    scanf("%lld %lld", &x, &k);
    if (x == 0){
        printf("0\n");
        return 0;
    }
    k %= mod-1;
    x %= mod;
    ll a = 1, mult = 2;
    for (; k; k>>=1){
        if (k%2 == 1)
            a = (a*mult)%mod;
        mult = (mult*mult)%mod;
    }
    printf("%lld\n", ((a*((2*x-1)%mod)+1)%mod+mod)%mod);
}
