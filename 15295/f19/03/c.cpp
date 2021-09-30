#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

ll dp[102][102][102], p[102][102];
int c[102];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i<n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i<n; i++)
		for (int j = 1; j<=m; j++)
			scanf("%lld", &p[i][j]);
	for (int i = 0; i<102; i++)
		for (int j = 0; j<102; j++)
			for (int kk = 0; kk < 102; kk++)
				dp[i][j][kk] = 1e18;
	if (c[0] == 0)
		for (int c1 = 1; c1 <= m; c1++)
			dp[0][1][c1] = p[0][c1];
	else
		dp[0][1][c[0]] = 0;
	for (int i = 1; i<n; i++) {
		if (c[i] == 0) {
			for (int kk = 1; kk <= n; kk++) {
				for (int c1 = 1; c1 <= m; c1++) {
					for (int cc = 1; cc <= m; cc++) {
						if (c1 == cc)
							dp[i][kk][c1] = min(dp[i][kk][c1], dp[i-1][kk][cc] + p[i][c1]);
						else
							dp[i][kk][c1] = min(dp[i][kk][c1], dp[i-1][kk-1][cc] + p[i][c1]);
					}
				}
			}
		}
		else {
			for (int kk = 1; kk <= n; kk++) {
				for (int cc = 1; cc <= m; cc++) {
					if (c[i] == cc)
						dp[i][kk][c[i]] = min(dp[i][kk][c[i]], dp[i-1][kk][cc]);
					else
						dp[i][kk][c[i]] = min(dp[i][kk][c[i]], dp[i-1][kk-1][cc]);
				}
			}
		}
//		for (int j = 1; j <= k; j++)
//			for (int c1 = 1; c1 <= m; c1++)
//				printf("dp[%d][%d][%d] = %lld\n", i, j, c1, dp[i][j][c1]);
	}
	ll ans = 1e18;
	for (int c1 = 1; c1 <= m; c1++)
		ans = min(ans, dp[n-1][k][c1]);
	if (ans == 1e18)
		ans = -1;
	printf("%lld\n", ans);
}
