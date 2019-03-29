#include <bits/stdc++.h>
using namespace std;

int h[100005], dp[100005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	dp[1] = abs(h[0] - h[1]);
	for (int i = 2; i < n; i++) {
		dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
	}
	printf("%d", dp[n - 1]);
}