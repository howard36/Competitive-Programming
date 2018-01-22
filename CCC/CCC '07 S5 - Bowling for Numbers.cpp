#include <cstdio>
#include <algorithm>
using namespace std;
int dp[501][30000], num[30000], psa[30000];
int t, n, k, w;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &n, &k, &w);
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		psa[0] = num[0];
		for (int i = 1; i < n + 2 * w; i++)
			psa[i] = psa[i - 1] + num[i];

		for (int i = 1; i <= k; i++)
			for (int j = 0; j < w; j++)
				dp[i][j] = psa[j];

		for (int i = 1; i <= k; i++)
			for (int j = w; j < n; j++)
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - w] + psa[j] - psa[j-w]);

		printf("%d\n", dp[k][n - 1]);
	}
	return 0;
}