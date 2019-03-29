#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t[2003];
ll c[2003], dp[2003][2003];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %lld", &t[i], &c[i]);
		t[i]++;
	}
	for (int i = 1; i <= n; i++) {
		dp[0][i] = 1e18;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][max(0, j - t[i])] + c[i]);
		}
	}
    printf("%lld", dp[n][n]);
}