#include <bits/stdc++.h>
using namespace std;

int h[100005], dp[100005];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = 1; i < n; i++) {
        dp[i] = 1e9;
        for (int j = i - 1; j >= max(i-k, 0); j--){
            dp[i] = min(dp[j] + abs(h[j] - h[i]), dp[i]);
        }
	}
	printf("%d", dp[n - 1]);
}