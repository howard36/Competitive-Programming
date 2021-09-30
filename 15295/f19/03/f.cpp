#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

int dp[102][50][2], a[102], b[102];

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i<50; i++)
		dp[0][i][0] = abs(i - a[0]);
	for (int i = 1; i<n; i++) {
		for (int j = 1; j<50; j++) {
			dp[i][j][0] = 1e9;
			for (int k = 1; k<50; k++) {
				if (gcd(j, k) == 1) {
					if (dp[i-1][k][0] + abs(j-a[i]) < dp[i][j][0]) {
						dp[i][j][0] = dp[i-1][k][0] + abs(j - a[i]);
						dp[i][j][1] = k;
					}
				}
			}
		}
	}
	int best = 0;
	dp[n-1][0][0] = 1e9;
	for (int i = 1; i<50; i++)
		if (dp[n-1][best][0] > dp[n-1][i][0])
			best = i;
	for (int i = n-1; i >= 0; i--) {
		b[i] = best;
		best = dp[i][best][1];
	}
	for (int i = 0; i<n; i++)
		printf("%d ", b[i]);
}
