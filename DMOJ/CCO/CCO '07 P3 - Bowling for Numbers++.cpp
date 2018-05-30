#include <cstdio>
#include <algorithm>
using namespace std;
int dp[501][10200], num[10200], psa[10200];
int t, n, k, w;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &n, &k, &w);
		for (int i = 0; i < w; i++)
			num[i] = 0;
		for (int i = w; i < n + w; i++)
			scanf("%d", &num[i]);
		for (int i = n + w; i < n + 2 * w; i++)
			num[i] = 0;

		for (int i = 1; i < n + 2 * w; i++)
			psa[i] = psa[i - 1] + num[i];

		for (int i = 1; i <= k; i++)
			for (int j = 0; j < w; j++)
				dp[i][j] = 0;

		for (int j = w; j < n + 2 * w; j++)
			dp[1][j] = max(dp[1][j - 1], psa[j] - psa[j - w]);

		for (int i = 2; i <= k; i++)
			for (int j = w; j < n + 2 * w; j++)
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - w] + psa[j] - psa[j - w]);
				for (int end = j - 1; end > j - w; end--)
					dp[i][j] = max(dp[i][j], dp[i - 2][max(0, end - w)] + psa[j] - psa[max(0, end - w)]);
			}

		printf("%d\n", dp[k][n + 2 * w - 1]);
	}
    return 0;
}