#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m, a, b;
    scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
    ll r = n/m;
    ll cost = min(b*(n-r*m), ((r+1)*m-n)*a);
    printf("%lld", cost);
}
