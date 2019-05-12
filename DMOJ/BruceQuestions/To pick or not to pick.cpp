#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,ll> 

int f[100005];
vector<pi> v;
ll dp[100005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        int a;
        scanf("%d", &a);
        f[a]++;
    }
    for (int i = 0; i<100005; i++){
        if (f[i])
            v.push_back(pi(i, 1LL*i*f[i]));
    }
    dp[0] = v[0].second;
    int m = v.size();
    if (m > 1){
        if (v[1].first - v[0].first == 1)
            dp[1] = max(dp[0], v[1].second);
        else 
            dp[1] = dp[0] + v[1].second;
    }
    for (int i = 2; i<m; i++){
        if (v[i].first - v[i-1].first == 1)
            dp[i] = max(dp[i-1], v[i].second + dp[i-2]);
        else
            dp[i] = dp[i-1] + v[i].second;
    }
    printf("%lld", dp[m-1]);
}