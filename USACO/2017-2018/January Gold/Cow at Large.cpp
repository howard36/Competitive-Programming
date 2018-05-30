#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

int parent[100005], depth[100005];
vector<int> adj[100005];
bool current[100005];
set<pi> leaves;

void dfs(int v, int d) {
	depth[v] = d;
	for (int u : adj[v]) {
		if (u != parent[v]) {
			parent[u] = v;
			dfs(u, d + 1);
		}
	}
}

void add(int v) {
	if (adj[v].size() == 1)
		leaves.erase(make_pair(depth[v], v));
	else {
		for (int u : adj[v]) {
			if (u != parent[v])
				add(u);
		}
	}
}

int main()
{
	FILE *fin = fopen("atlarge.in", "r");
	FILE *fout = fopen("atlarge.out", "w");
	int N, K, a, b;
	fscanf(fin, "%d%d", &N, &K);
	for (int i = 1; i < N; i++) {
		fscanf(fin, "%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if (adj[K].size() == 1) {
		fprintf(fout, "1");
		return 0;
	}

	dfs(K, 0);

	for (int i = 1; i <= N; i++) {
		if (adj[i].size() == 1) {
			leaves.insert(make_pair(depth[i], i));
		}
	}

	int count = 0;
	while (!leaves.empty()) {
		pi p = *leaves.begin();
		int d = p.first, v = p.second;
		for (int i = 0; i < d / 2; i++) {
			v = parent[v];
		}
		add(v);
		count++;
	}

	fprintf(fout, "%d", count);
    return 0;
}
