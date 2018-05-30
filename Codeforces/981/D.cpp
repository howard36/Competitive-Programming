#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[51], psa[51];
int N, K;
set<int> dp[51];

bool check(ll x){
    dp[0].insert(0);
    for (int i = 1; i<=N; i++){
        dp[i].clear();
        for (int j = 0; j<i; j++){
            if (((psa[i]-psa[j])&x) == x){
                for (int u : dp[j])
                    dp[i].insert(u+1);
            }
        }
    }
    return dp[N].find(K) != dp[N].end();
}

int main(){
    // freopen("data.txt", "r", stdin);
    scanf("%d%d", &N, &K);
    for (int i = 1; i<=N; i++){
        scanf("%lld", &a[i]);
        psa[i] = psa[i-1] + a[i];
        // printf("%lld ", psa[i]);
    }
    // printf("\n");
    ll ans = 0;
    for (int test = 56; test>=0; test--){
        if (check(ans+(1LL<<test))){
        // printf("%d %lld\n", test, ans);
            ans += (1LL<<test);
        }
    }
    printf("%lld", ans);
}
