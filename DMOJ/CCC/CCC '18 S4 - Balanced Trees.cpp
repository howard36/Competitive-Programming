#include <cstdio>
#define ll long long

ll dp[1000003], diff[1000003];

ll calc(int N) {
	if (dp[N] != 0)
		return dp[N];
	ll ans = 0;
	for (int d = 1; d <= N/2; d++) {
		ans += calc(d) * (N / d - N / (d + 1));
	}
	dp[N] = ans;
	return ans;
}

int main()
{
	int N;
	scanf("%d", &N);
	dp[1] = 1;
	printf("%lld", calc(N));
	for (int i = 1; i < N / 2; i++) {
		diff[i] = dp[i] - dp[i - 1];
	}
    return 0;
}