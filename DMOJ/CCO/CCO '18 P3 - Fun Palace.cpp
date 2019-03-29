#include <bits/stdc++.h>
using namespace std;

int a[1003], b[1003], dp[1003][20004];

int main() {
	int n;
	scanf("%d %d", &n, &b[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < b[0]; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int m = 0;
		for (int j = 0; j < a[i]; j++) {
			m = max(m, dp[i - 1][j]);
		}
		for (int j = 0; j < 20000; j++) {
			if (j < b[i]) {
				dp[i][j] = m + j;
			}
			else if (j < a[i] + b[i]) {
				dp[i][j] = b[i] + dp[i - 1][j - b[j]];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	int m = 0;
	for (int i = 0; i < 20000; i++) {
		m = max(m, dp[n][i]);
	}
	printf("%d\n", m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 25; j++) {
			printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
	}
}