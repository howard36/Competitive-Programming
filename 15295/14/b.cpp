#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define pb push_back

ll dist[100005];
priority_queue<pi> pq;
vector<pi> adj[100005];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i<m; i++) {
		ll a, b, w;
		cin >> a >> b >> w;
		adj[a].pb(pi(b,w));
		adj[b].pb(pi(a,w));
	}
	for (int i = 2; i<=n; i++)
		dist[i] = 1e18;
	pq.push(pi(0, 1));
	while (!pq.empty()) {
		pi p = pq.top();
		pq.pop();
		ll v = p.second;
		if (-p.first > dist[v])
			continue;
		for (pi q : adj[v]) {
			ll u = q.first;
			if (dist[u] > dist[v] + q.second) {
				dist[u] = dist[v] + q.second;
				pq.push(pi(-dist[u], u));
			}
		}
	}
	for (int i = 1; i<=n; i++)
		cout << "dist[" << i << "] = " << dist[i] << endl;
	int ans = 0;
	for (int i = 0; i<k; i++) {
		ll v, d;
		cin >> v >> d;
		if (dist[v] <= d)
			ans++;
	}
	cout << ans << endl;
}
