#include <bits/stdc++.h>
using namespace std;

int dp[4003];

int main() {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    for (int i = 1; i<=n; i++){
        dp[i] = -1e9;
        if (i >= a)
            dp[i] = max(dp[i], dp[i-a] + 1);
        if (i >= b)
            dp[i] = max(dp[i], dp[i-b] + 1);
        if (i >= c)
            dp[i] = max(dp[i], dp[i-c] + 1);
    }
    printf("%d", dp[n]);
}