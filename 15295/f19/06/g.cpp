#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define ppi pair<pi, int>

vector<pi> adj[100005];
ll dist[100005];
set<pi> s;
int back[100005], path[100005];
vector<ppi> ans;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		ll w = 1000001 - z;
		adj[x].push_back(pi(y, w));
		adj[y].push_back(pi(x, w));
	}
	for (int i = 2; i<=n; i++)
		dist[i] = 1e18;
	s.insert(pi(0, 1));
	while (!s.empty()) {
		pi p = *(s.begin());
		s.erase(s.begin());
		ll d = p.first, v = p.second;
		if (dist[v] < d)
			continue;
		for (pi &q : adj[v]) {
			ll u = q.first;
			if (dist[v] + q.second < dist[u]) {
				back[u] = v;
				dist[u] = dist[v] + q.second;
				s.insert(pi(dist[u], u));
			}
		}
	}

	memset(path, -1, sizeof path);
	int v = n;
	while (v != 1) {
		int a = v, b = back[v];
		path[a]= b;
		v = back[v];
	}

	for (int i = 1; i<=n; i++) {
		for (pi &p : adj[i]) {
			ll j = p.first, w = p.second;
			if (i < j)
				continue;
			if (j != path[i] && i != path[j]) {
				if (w == 1000000)
					ans.push_back(ppi(pi(i, j), 0));
			}
			else {
				if (w == 1000001)
					ans.push_back(ppi(pi(i, j), 1));
			}
		}
	}

	printf("%d\n", ans.size());
	for (ppi p : ans) {
		printf("%lld %lld %d\n", p.first.first, p.first.second, p.second);
	}
}
