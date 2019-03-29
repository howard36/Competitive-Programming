#include <bits/stdc++.h>

int cur[4];
double dp[302][302][302];
int n;

double solve(int i, int j, int k) {
	if (i + j + k == 0)
		return 0;
	if (dp[i][j][k] != 0)
		return dp[i][j][k];
	dp[i][j][k] = 1;
	if (i > 0)
		dp[i][j][k] += solve(i - 1, j, k) * i / n;
	if (j > 0)
		dp[i][j][k] += solve(i + 1, j - 1, k) * j / n;
	if (k > 0)
		dp[i][j][k] += solve(i, j + 1, k - 1) * k / n;
	return dp[i][j][k];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		cur[a]++;
	}
	printf("%.10lf", solve(cur[1], cur[2], cur[3]));
}