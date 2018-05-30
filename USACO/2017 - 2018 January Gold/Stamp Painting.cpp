#include <bits/stdc++.h>
#define ll long long
const ll mod = 1000000007LL;

ll powM[1000006], dp[1000006], dp2[1000006];

int main() {
	FILE *fin = fopen("spainting.in", "r");
	FILE *fout = fopen("spainting.out", "w");
	int N, K, M;
	fscanf(fin, "%d%d%d", &N, &M, &K);
	powM[0] = 1LL;
	for (int i = 1; i <= N - K; i++)
		powM[i] = (powM[i - 1] * M) % mod;
	for (int n = K; n <= N; n++) {
		dp[n] = (((n - K + 1)*powM[n - K] - dp2[n - K]) % mod)*(M-1)+powM[n-K];
		dp2[n] = (M*dp2[n - 1] + dp[n]) % mod;
	}
	fprintf(fout, "%lld", (dp[N] + mod) % mod);
    return 0;
}
