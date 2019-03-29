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
    for (int i = 1; i < 100005; i++)
        dp[0][i] = 1e18;
	for (int i = 1; i <= n; i++) {
		dp[i][100001] = 1e18;
		for (int j = 100000; j >= 0; j--) {
			dp[i][j] = min(dp[i][j + 1], dp[i - 1][j]);
			if (j >= v[i]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
			}
		}
	}
    for (int i = 100000; i>=0; i--){
        if (dp[n][i] <= W){
            printf("%d", i);
            return 0;
        }
    }
}