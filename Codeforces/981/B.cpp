#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll,ll> money;

int main(){
    // freopen("data.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    ll sum = 0;
    while (n--){
        ll a, x;
        scanf("%lld %lld", &a, &x);
        money[a] = x;
        sum += x;
    }
    scanf("%d", &m);
    while (m--){
        ll a, x;
        scanf("%lld %lld", &a, &x);
        if (money.find(a)!=money.end()){
            sum += x - min(x, money[a]);
        }
        else
            sum += x;
    }
    printf("%lld\n", sum);
}
