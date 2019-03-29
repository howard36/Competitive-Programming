#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<ll, ll>

ll x[200005], y[200005], dist[200005];
int s[200005], e[200005], in[200005], good[200005];
vector<pl> adj[200005], rev[200005];
priority_queue<pl, vector<pl>, greater<pl>> pq;
queue<int> topocheck;
vector<int> toposort;

void topologicalSort(int start) {
	topocheck.push(start);
	while (!topocheck.empty()) {
		int v = topocheck.front();
		topocheck.pop();
		toposort.push_back(v);
		for (pl p : adj[v]) {
			int u = p.first;
			in[u]--;
			if (in[u] <= 0)
				topocheck.push(u);
		}
	}
}

int main() {
	ll n, t;
	FILE *fin = fopen("mowing.in", "r");
	FILE *fout = fopen("mowing.out", "w");
	fscanf(fin, "%lld %lld", &n, &t);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%lld %lld", &x[i], &y[i]);
		adj[n].push_back(pl(i, x[i] * y[i]));
		rev[i].push_back(pl(n, x[i] * y[i]));
		adj[i].push_back(pl(n + 1, (t - x[i]) * (t - y[i])));
		rev[n + 1].push_back(pl(i, (t - x[i]) * (t - y[i])));
		in[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i] < x[j] && y[i] < y[j]) {
				adj[i].push_back(pl(j, (x[j] - x[i]) * (y[j] - y[i])));
				rev[j].push_back(pl(i, (x[j] - x[i]) * (y[j] - y[i])));
				in[j]++;
			}
		}
	}

	adj[n].push_back(pl(n + 1, t * t));
	rev[n + 1].push_back(pl(n, t * t));
	in[n + 1] = n + 1;

	topologicalSort(n);

	for (int i = 0; i < n + 2; i++) {
		int v = toposort[i];
		for (pl p : adj[v]) {
			int u = p.first;
			if (s[v] + 1 > s[u])
				s[u] = s[v] + 1;
		}
	}

	for (int i = n + 1; i >= 0; i--) {
		int v = toposort[i];
		for (pl p : rev[v]) {
			int u = p.first;
			if (e[v] + 1 > e[u])
				e[u] = e[v] + 1;
		}
	}

	for (int i = 0; i < n + 2; i++) {
		if (s[i] + e[i] == s[n + 1])
			good[i] = 1;
	}

	// printf("toposort: ");
	// for (int i = 0; i<toposort.size(); i++){
	//     printf("%d, ", toposort[i]);
	// }
	// printf("\n");

	// for (int i = 0; i < n + 2; i++) {
	// 	printf("i = %d, s = %d, e = %d, good = %d\n", i, s[i], e[i], good[i]);
	// }

	for (int i = 0; i < n; i++) {
		dist[i] = 1e18;
	}
	dist[n + 1] = 1e18;

	pq.push(pl(0, n));
	while (!pq.empty()) {
		pl p = pq.top();
		pq.pop();
		ll d = p.first;
		int v = p.second;
		if (d > dist[v])
			continue;
		for (pl next : adj[v]) {
			int u = next.first;
			if (!good[u])
				continue;
			if (dist[v] + next.second < dist[u]) {
				dist[u] = dist[v] + next.second;
				pq.push(pl(dist[u], u));
			}
		}
	}
	fprintf(fout, "%lld\n", dist[n + 1]);
}