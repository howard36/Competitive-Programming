#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[20004], psa[20004], dp[20004][2], dp2[20004];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		psa[i] = a[i] + psa[i - 1];
	}
	for (int kk = 1; kk <= k; kk++) {
		dp2[0] = dp[0][(kk - 1) % 2];
		for (int i = 0; i <= n; i++)
			dp2[i] = max(dp2[i - 1], dp[i][(kk - 1) % 2] - psa[i]);
		for (int i = 0; i < kk; i++)
			dp[i][kk % 2] = -1e18;
		for (int i = kk; i <= n; i++)
			dp[i][kk % 2] = max(dp[i - 1][kk % 2], dp2[i - 1] + psa[i]);
	}
	printf("%lld", dp[n][k % 2]);
}