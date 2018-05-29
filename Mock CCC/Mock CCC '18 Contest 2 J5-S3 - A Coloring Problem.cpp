#include <cstdio>
#include <algorithm>
using namespace std;

int grid[40][40];
long long dp[40][40];
int maxB[40], minR[40];

int main()
{
	int m, n;
	char chr;
	scanf("%d%d", &m, &n);
	for (int r = 1; r <= m; r++) {
		for (int c = 1; c <= n; c++) {
			scanf(" %c", &chr);
			if (chr == 'B')
				grid[r][c] = 1;
			else if (chr == 'R')
				grid[r][c] = 2;
		}
	}
	/*
	bool valid = true;
	for (int r1 = 1; r1 <= m; r1++) {
		for (int c1 = 1; c1 <= n; c1++) {
			for (int r2 = 1; r2 <= r1; r2++) {
				for (int c2 = 1; c2 <= c1; c2++) {
					if (grid[r1][c1] == 1 && grid[r2][c2] == 2)
						valid = false;
				}
			}
		}
	}
	if (!valid)	{
		printf("0");
		return 0;
	}
	*/
	minR[0] = m + 1; minR[n + 1] = 1;
	for (int c = 1; c <= n; c++) {
		int r = 1;
		for (; r <= m; r++) {
			if (grid[r][c] == 2) {
				break;
			}
		}
		minR[c] = min(minR[c - 1], r);
	}
	maxB[n + 1] = 0; maxB[0] = m;
	for (int c = n; c > 0; c--) {
		int r = m;
		for (; r > 0; r--) {
			if (grid[r][c] == 1) {
				break;
			}
		}
		maxB[c] = max(maxB[c + 1], r);
	}
	dp[m][0] = 1;
	for (int c = 1; c <= n + 1; c++) {
		long long sum = 0;
		for (int r = m; r >= maxB[c]; r--) {
			sum += dp[r][c-1];
			if (r < minR[c])
				dp[r][c] = sum;
		}
	}
	printf("%lld", dp[0][n + 1]);
    return 0;
}