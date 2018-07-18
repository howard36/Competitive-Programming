#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

bool simulate(ll k){
    ll x = n, turn = 0, good = 0, bad = 0;
    while (x > 0){
        if (turn%2){
            bad += x/10;
            x -= x/10;
        }
        else{
            good += min(x, k);
            x -= k;
        }
        turn++;
    }
    return 2*good >= n;
}

int main() {
    scanf("%lld", &n);
    ll lo = 1, hi = n;
    while (lo < hi){
        ll mid = (lo+hi)/2;
        if (simulate(mid)){
            hi = mid;
        }
        else
            lo = mid+1;
    }
    printf("%lld", lo);
}
