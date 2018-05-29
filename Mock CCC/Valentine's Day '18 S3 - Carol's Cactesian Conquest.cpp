#include <cstdio>
#define ll long long
const ll mod = 1000000007LL;

ll dps[102], dpb[102], dp2[102][102], choose[102][102];

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	choose[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			choose[i][j] %= mod;
			choose[i + 1][j] += choose[i][j];
			choose[i + 1][j + 1] += choose[i][j];
		}
	}
	dp2[0][1] = 1; dp2[0][2] = 1;
	for (int k = 3; k <= K + 1; k++) {
		dp2[0][k] = 1;
		dp2[1][k] = 1;
	}
	for (int n = 2; n <= N; n++) {
		for (int k = 1; k <= K + 1; k++) {
			for (int i = 0; i < n - 1; i++) {
				if (n == 2 && k == 2) {
					int x = 0;
				}
				dp2[n][k] += ((choose[n-1][i] * dp2[i][k]) % mod)*dp2[n - i - 1][k] % mod;
				dp2[n][k] %= mod;
			}
			dp2[n][k] += dp2[n - 1][k - 1];
		}
	}
	dps[0] = 1;
	for (int n = 1; n <= N; n++) {
		for (int i = 0; i < n; i++) {
			dps[n] += ((choose[n - 1][i] * dp2[i][K]) % mod)*dps[n - i - 1] % mod;
			dps[n] %= mod;
		}
	}
	dpb[0] = 1;
	for (int n = 1; n <= N; n++) {
		for (int i = 0; i < n; i++) {
			dpb[n] += ((choose[n - 1][i] * dp2[i][K+1]) % mod)*dpb[n - i - 1] % mod;
			dpb[n] %= mod;
		}
	}
	int ans = (((dpb[N] - dps[N]) % mod) + mod) % mod;
	printf("%d", ans);
    return 0;
}