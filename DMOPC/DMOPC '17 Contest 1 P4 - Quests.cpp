#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll g[5000], h[5000], q[5000], t[5000];
ll dp[2][5001];

int main()
{
	int N, H;
	scanf("%d %d", &N, &H);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &g[i], &h[i], &q[i], &t[i]);
	for (int j = h[0]; j <= H; j++)
		dp[0][j] = g[0] + q[0] * ((j - h[0]) / t[0]);
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= H; j++)
		{
			if (j >= h[i])
				dp[i & 1][j] = dp[i & 1 ^ 1][j - h[i]] + g[i];
			else
				dp[i & 1][j] = 0;
		}
		for (int j = 1; j <= H; j++)
		{
			if (j >= h[i] + t[i])
				dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1][j - t[i]] + q[i]);
		}
		for (int j = 1; j <= H; j++)
			dp[i&1][j] = max(dp[i&1][j], dp[i&1^1][j]);
	}
	printf("%lld", dp[(N&1)^1][H]);
    return 0;
}