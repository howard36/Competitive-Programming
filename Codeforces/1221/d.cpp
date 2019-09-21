#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

ll dp[300005][3], a[300005], b[300005];

int main() {
	int n, q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		for (int i = 0; i<n; i++)
			scanf("%lld %lld", &a[i], &b[i]);
		dp[0][0] = 0;
		dp[0][1] = b[0];
		dp[0][2] = 2*b[0];
		for (int i = 1; i<n; i++) {
			for (int j = 0; j<3; j++) {
				dp[i][j] = 1e18;
				for (int k = 0; k<3; k++) {
					if (a[i] + j != a[i-1] + k) {
						dp[i][j] = min(dp[i-1][k] + j*b[i], dp[i][j]);
					}
				}
			}
		}
		printf("%lld\n", min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]));
	}
}
