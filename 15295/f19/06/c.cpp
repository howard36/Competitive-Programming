#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define ppi pair<pi, int>

set<pi> s;
ll dist[300005];
vector<ppi> adj[300005];
pi ans[300005];
vector<pi> adj2[300005];
int prnt = 0;

void dfs(int v, int par) {
	if (prnt == 0)
		return;
	for (pi p : adj2[v]) {
		if (p.first == par)
			continue;
		if (prnt == 0)
			return;
		printf("%d ", p.second);
		prnt--;
		if (prnt == 0)
			break;
		dfs(p.first, v);
	}
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i<=m; i++) {
		int a, b;
		ll w;
		scanf("%d %d %lld", &a, &b, &w);
		adj[a].push_back(ppi(pi(w, b), i));
		adj[b].push_back(ppi(pi(w, a), i));
	}
	for (int i = 2; i<=n; i++) {
		dist[i] = 1e18;
	}
	s.insert(pi(0, 1));
	while (!s.empty()) {
		pi p = *(s.begin());
		s.erase(s.begin());
		ll d = p.first, v = p.second;
		if (dist[v] < d)
			continue;
		for (ppi &q : adj[v]) {
			ll u = q.first.second;
			if (dist[v] + q.first.first < dist[u]) {
				ans[u] = pi(v, q.second);
				dist[u] = dist[v] + q.first.first;
				s.insert(pi(dist[u], u));
			}
		}
	}
	for (int i = 2; i<=n; i++)
		adj2[ans[i].first].push_back(pi(i, ans[i].second));
	printf("%d\n", min(k, n-1));
	prnt = min(k, n-1);
	dfs(1, -1);
}
