#include <bits/stdc++.h>
using namespace std;
#define ll long long

int c[1000006], best[1000006];
ll v[1000006], dp[1000006], prefix[1000006];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i<=n; i++){
        scanf("%d", &c[i]);
    }
    for (int i = 1; i<=n; i++){
        scanf("%lld", &v[i]);
        prefix[i] = prefix[i-1] + v[i];
    }
    for (int i = 1; i<=n; i++){
        if (best[c[i]]){
            dp[i] = max(dp[i-1], prefix[i] - prefix[best[c[i]]-1] + dp[best[c[i]]-1]);
            if (dp[i-1] > prefix[i-1] - prefix[best[c[i]]-1] + dp[best[c[i]]-1])
                best[c[i]] = i;
        }else{
            dp[i] = dp[i-1];
            best[c[i]] = i;
        }
    }
    printf("%lld", dp[n]);
}