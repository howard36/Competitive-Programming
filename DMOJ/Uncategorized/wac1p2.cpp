#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int vis[100005];

void dfs(int v) {
	vis[v] = 1;
	for (int u : adj[v]) {
		if (!vis[u])
			dfs(u);
	}
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cc = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			cc++;
		}
	}
	int move = min(m - (n - cc), k);
	printf("%d\n", max(cc - 1 - move, 0));
}