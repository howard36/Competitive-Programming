#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll v[100005], dp[100005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        ll a;
        scanf("%lld", &a);
        v[a] += a;
    }
    dp[1] = v[1];
    for (int i = 2; i<=1e5; i++){
        dp[i] = max(dp[i-1], dp[i-2] + v[i]);
    }
    printf("%lld", dp[100000]);
}