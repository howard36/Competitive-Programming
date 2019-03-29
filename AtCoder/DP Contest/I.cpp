#include <bits/stdc++.h>

double dp[3003][3003], p[3003], q[3003];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &p[i]);
		q[i] = 1 - p[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] * q[i];
		dp[i][i] = dp[i - 1][i - 1] * p[i];
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] * q[i] + dp[i - 1][j - 1] * p[i];
		}
	}
    double ans = 0;
    for (int i = n/2 + 1; i<=n; i++){
        ans += dp[n][i];
    }
    printf("%.10lf", ans);
}