#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll w[102], v[102], dp[102][100005];

int main() {
	int n;
	ll W;
	scanf("%d %lld", &n, &W);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &w[i], &v[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	printf("%lld", dp[n][W]);
}