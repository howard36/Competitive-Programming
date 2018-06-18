#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> primepow;

int main() {
    // freopen("data.txt", "r", stdin);
    ll x, y, l, r;
    scanf("%lld%lld%lld%lld", &l, &r, &x, &y);
    if (y%x != 0){
        printf("0\n");
        return 0;
    }
    ll n = y/x;
    for (ll d = 2; d*d <= n; d++){
        if (n%d == 0){
            primepow.push_back(1);
            while (n%d == 0){
                n/=d;
                primepow[primepow.size()-1] *= d;
            }
        }
    }
    if (n > 1)
        primepow.push_back(n);
    int p = primepow.size(), count = 0;
    for (ll i = 0; i<(1LL<<p); i++){
        ll a = 1, b = 1;
        for (int j = 0; j<p; j++){
            if (i&(1LL<<j))
                a *= primepow[j];
            else
                b *= primepow[j];
        }
        if (a*x >= l && a*x <= r && b*x >= l && b*x <= r)
            count++;
    }
    printf("%d\n", count);
}
