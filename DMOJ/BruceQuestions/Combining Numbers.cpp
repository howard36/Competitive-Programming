#include <bits/stdc++.h>
using namespace std;

int dp[300005][60], a[300005], b[300005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	memset(dp, -1, sizeof dp);
	dp[0][a[0]] = 0;
	for (int i = 1; i < n; i++) {
        dp[i][a[i]] = i;
		for (int j = a[i] + 1; j < 60; j++) {
            if (dp[i][j-1] > 0 && dp[dp[i][j-1]-1][j-1] != -1)
                dp[i][j] = dp[dp[i][j-1]-1][j-1];
		}
	}
    int m;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<60; j++){
            if (dp[i][j] != -1)
                m = max(m, j);
        }
    }
    printf("%d", m);
}