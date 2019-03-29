#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007LL

ll dp[5003][5003];
char c[5003];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c[i]);
	}
	dp[n][0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (c[i] == 'f') {
			for (int j = 0; j < n; j++) {
				dp[i][j] = dp[i + 1][j + 1];
			}
		}
		else {
			ll sum = 0;
			for (int j = 0; j < n; j++) {
				sum = (sum + dp[i + 1][j]) % mod;
				dp[i][j] = sum;
			}
		}
	}
    printf("%lld", dp[0][0]);
}