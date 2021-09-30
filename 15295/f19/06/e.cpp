#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

ll a[100005];
int vis[100005], dist[100005];
int ans = 1e9;
vector<int> adj[100005];
int par[100005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i<60; i++) {
		vector<int> v;
		for (int j = 0; j<n; j++) {
			if ((a[j]>>i)&1)
				v.push_back(j);
		}
		if (v.size() > 2) {
			printf("3\n");
			return 0;
		}
		if (v.size() == 2) {
			adj[v[0]].push_back(v[1]);
			adj[v[1]].push_back(v[0]);
		}
	}
	for (int i = 0; i<n; i++) {
		if (adj[i].size() > 0) {
			memset(vis, 0, sizeof vis);
			for (int j=0; j<n; j++)
				dist[j] = 1e9;
			queue<int> q;
			q.push(i);
			dist[i] = 0;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				vis[v] = 1;
				for (int u : adj[v]) {
					if (u == par[v])
						continue;
					if (vis[u]) {
						ans = min(ans, dist[v] + dist[u] + 1);
						break;
					}
					if (dist[v] + 1 < dist[u]) {
						dist[u] = dist[v] + 1;
						par[u] = v;
						q.push(u);
					}
				}
			}
		}
	}
	if (ans == 1e9)
		ans = -1;
	printf("%d\n", ans);
}
