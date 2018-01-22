#include <cstdio>
#include <algorithm>
using namespace std;

double dp[1003][1003]; //dp[n][i] is probability for position i out of n people
int main()
{
	int N, K, I;
	scanf("%d%d%d", &N, &K, &I);
	if (N <= 1000)
	{
		dp[1][1] = 1.0;
		for (int n = 2; n <= N; n++)
			for (int i = 1; i <= n; i++)
				dp[n][i] = (((1 + K / n)*(i - 1) + min(K%n, i - 1)) * dp[n - 1][i - 1] + ((1 + K / n)*(n - i) + max(K%n - i, 0)) * dp[n - 1][i]) / (n + K);
		printf("%.8e", dp[N][I]);
	}
	else
	{
		if (K == 0)
			printf("%.8e", 1.0 / N);
		else if (K == 1)
			printf("%.8e", 2.0*I / ((double)N*(N + 1)));
		else
			printf("%.8e", 2.0*(I+1) / ((double)(N + 1)*(N + 2)));
	}
    return 0;
}