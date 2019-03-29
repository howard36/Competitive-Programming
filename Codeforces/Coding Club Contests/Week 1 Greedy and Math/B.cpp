#include <bits/stdc++.h>
using namespace std;
#define ll long long

int blocked[1000006], back[1000006];
ll cost[1000006];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int s;
		scanf("%d", &s);
		blocked[s] = 1;
	}
	if (blocked[0]) {
		printf("-1");
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &cost[i]);
	}
	for (int i = 0; i < n; i++) {
		if (blocked[i])
			back[i] = back[i - 1];
		else
			back[i] = i;
	}

	ll best = 1e18;
	for (int i = 1; i <= k; i++) {
		int cur = 0, count = 0;
		while (true) {
			count++;
			if (cur + i >= n) {
				best = min(best, cost[i] * count);
				break;
			}
			int next = back[cur + i];
			if (next == cur)
				break;
			else
				cur = next;
		}
	}
	if (best == 1e18)
		printf("-1");
	else
		printf("%lld", best);
}