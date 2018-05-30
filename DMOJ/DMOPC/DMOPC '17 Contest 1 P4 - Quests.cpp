#include <cstdio>
#include <algorithm>
using namespace std;

int g[5000], h[5000], q[5000], t[5000];
int dp1[5001];
int dp2[5001][5001];

int main()
{
	int N, H; bool subcase2 = true;
	scanf("%d %d", &N, &H);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &g[i], &h[i], &q[i], &t[i]);
		if (g[i] != q[i] || h[i] != t[i])
			subcase2 = false;
	}
	if (subcase2)
	{
		for (int j = 1; j <= H; j++)
		{
			for (int i = 0; i < N; i++)
			{
				if (h - t[i] >= 0)
					dp1[j] = max(dp1[j], dp1[j - t[i]] + q[i]);
			}
		}
		printf("%d", dp1[H]);
	}
	else
	{
		for (int j = h[0]; j <= H; j++)
			dp2[0][j] = g[0] + q[0] * ((j - h[0]) / t[0]);
		for (int i = 1; i < N; i++)
		{
			for (int j = h[i]; j <= H; j++)
			{
				dp2[i][j] = max(dp2[i - 1][j], dp2[i][j-1]);
				for (int k = 0; k <= (j - h[i]) / t[i]; k++)
					dp2[i][j] = max(dp2[i][j], g[i] + q[i] * k + dp2[i - 1][j - h[i] - t[i] * k]);
			}
		}
		printf("%d", dp2[N - 1][H]);
	}
    return 0;
}