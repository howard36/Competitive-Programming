#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int dp[100005];

void solve(int v) {
	if (dp[v] != 0) {
		return;
	}
	dp[v] = 1;
	for (int u : adj[v]) {
		solve(u);
		dp[v] = max(dp[v], dp[u] + 1);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		solve(i);
		ans = max(ans, dp[i]);
	}
	printf("%d", ans - 1);
}