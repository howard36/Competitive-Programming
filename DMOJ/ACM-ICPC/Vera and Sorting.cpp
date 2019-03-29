#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

ll dp[31][1801], ch[31][31];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
    ch[0][0] = 1;
    for (int i = 1; i<=N; i++){
        ch[i][0] = 1;
        for (int j = 1; j<=i; j++){
            ch[i][j] = (ch[i-1][j-1] + ch[i-1][j]) % mod;
        }
    }
	dp[0][0] = 1;
	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= (i - 1) * (i - 1); j++) {
				for (int k = 0; k <= (N - i) * (N - i); k++) {
					dp[n][n + j + k] += (ch[n-1][i-1] * dp[i - 1][j] % mod) * dp[n - i][k];
					dp[n][n + j + k] %= mod;
				}
			}
		}
	}
	printf("%lld", dp[N][K]);
}