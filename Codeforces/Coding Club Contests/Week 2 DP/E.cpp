#include <bits/stdc++.h>
using namespace std;

int dp[102][3];

int main() {
	int n;
	scanf("%d", &n);
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
		if (a >= 2)
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		else
			dp[i][1] = 1e9;
		if (a % 2)
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		else 
			dp[i][2] = 1e9;
	}
    printf("%d", min(dp[n][0], min(dp[n][1], dp[n][2])));
}