#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> factors, fa, fb;

bool check(ll x, ll y, vector<ll> &v){
    ll a = v[v.size()-1];
    ll d = v[(upper_bound(v.begin(), v.end(), x) - v.begin()) - 1];
    return a / d <= y;
}

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll n = a+b;
    for (ll d = 1; d*d<=n; d++){
        if (n%d == 0){
            factors.push_back(d);
        }
    }
    reverse(factors.begin(), factors.end());

    for (ll d = 1; d*d<=a; d++){
        if (a%d == 0){
            fa.push_back(d);
            if (d*d < a)
                fa.push_back(a/d);
        }
    }
    for (ll d = 1; d*d<=b; d++){
        if (b%d == 0){
            fb.push_back(d);
            if (d*d < b)
                fb.push_back(b/d);
        }
    }
    sort(fa.begin(), fa.end());
    sort(fb.begin(), fb.end());

    for (int i = 0; i<factors.size(); i++){
        ll x = factors[i];
        ll y = n/x;
        if (check(x, y, fa) || check(x, y, fb)){
            printf("%lld", 2*(x+y));
            return 0;
        }
    }
}