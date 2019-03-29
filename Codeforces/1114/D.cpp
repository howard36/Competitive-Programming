#include <bits/stdc++.h>
using namespace std;

int c[5003], dp[5003][5003];

int main() {
	int n;
	scanf("%d %d", &n, &c[0]);
	int m = 1, x;
	for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		if (x != c[m - 1]) {
			c[m] = x;
			m++;
		}
	}
	for (int i = 0; i < m; i++) {
		dp[i][i] = 1;
        dp[i][i+1] = 1;
	}
	for (int l = 3; l <= m; l++) {
		for (int i = 0; i < m - l + 1; i++) {
			int j = i + l - 1;
            if (c[i] == c[j]){
                dp[i][j] = dp[i+1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
		}
	}
    printf("%d\n", m - dp[0][m-1]);
    // printf("%d %d", m, dp[0][m-1]);
}