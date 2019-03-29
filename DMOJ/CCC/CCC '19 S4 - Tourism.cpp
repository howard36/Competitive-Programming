
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000006];
ll dp[1000006];
ll sparse[1000006][21];
int lg[1000006];
int n;

void sparseInit() {
	for (int i = 0; i < n; i++) {
		sparse[i][0] = a[i];
	}
	for (int j = 1; j <= lg[n]; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
		}
	}
}

ll queryMax(int l, int r) {
	if (l == r)
		return a[l];
	int k = lg[r-l+1];
	return max(sparse[l][k], sparse[r - (1 << k) + 1][k]);
}

int main() {
	int k;
	scanf("%d %d", &n, &k);
	int b = (n - 1) / k + 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	lg[1] = 0;
	for (int i = 2; i <= n; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	sparseInit();
	dp[0] = a[0];
	for (int i = 1; i < k; i++) {
		dp[i] = max(dp[i - 1], a[i]);
	}

	for (int bb = 1; bb < b; bb++) {
		// compute dp[bb*k] in O(k)
		// this happens O(n/k) times, so O(n) total
		int idx = bb * k;
		ll m = a[idx];
		int lastBest = 0;
		for (int s = 1; s <= k; s++) {
			ll consider = dp[idx - s] + m;
			if (consider >= dp[idx]) {
				lastBest = idx - s;
				dp[idx] = consider;
			}
			m = max(m, a[idx - s]);
		}

		// compute dp[i] for i from idx + 1 to idx + k - 1
		for (int i = idx + 1; i < min(idx + k, n); i++) {
			int r = i % k + 1;
			if (i - lastBest > k)
				lastBest++;
			dp[i] = dp[lastBest] + queryMax(lastBest + 1, i);
			while (lastBest < i - r) {
				// check if lastBest + 1 is better than lastBest
				ll consider = dp[lastBest + 1] + queryMax(lastBest + 2, i);
				if (consider >= dp[i]) {
					dp[i] = consider;
					lastBest++;
				}
				else {
					break;
				}
			}
		}
	}
	printf("%lld", dp[n - 1]);
}