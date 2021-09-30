#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

pi edges[202];
vector<int> adj[202];
int dist[202];
int n;

void dfs(int v, int p, int d) {
	dist[v] = d;
	for (int i : adj[v]) {
		if (i != p)
			dfs(i, v, d+1);
	}
}

ll longest(int v) {
	memset(dist, -1, sizeof dist);
	dfs(v, -1, 0);
	int far = v;
	for (int i = 0; i<n; i++) {
		if (dist[i] != -1 && dist[i] > dist[far])
			far = i;
	}
	dfs(far, -1, 0);
	ll ans = 0;
	for (int i = 0; i<n; i++) {
		ans = max(ans, (ll)dist[i]);
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i<n-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edges[i] = pi(a-1, b-1);
	}
	ll ans = 0;
	for (int ii = 0; ii<n-1; ii++) {
		for (int i = 0; i<n; i++)
			adj[i].clear();
		for (int i = 0; i<n-1; i++) {
			if (i == ii)
				continue;
			pi e = edges[i];
			adj[e.first].push_back(e.second);
			adj[e.second].push_back(e.first);
		}
		ans = max(ans, 1LL * longest(edges[ii].first) * longest(edges[ii].second));
	}
	printf("%lld", ans);
}
