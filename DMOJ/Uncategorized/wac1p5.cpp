#include <bits/stdc++.h>
using namespace std;

int forced[25004], num[50004], low[50004], instack[50004], comp[50004], vis[50004], ans[25004];
bitset<50004> closure[50004], force;
vector<int> adj[50004], adj2[50004], s;
int nums = 1, comps = 0;

void tarjan(int v) {
	num[v] = low[v] = nums++;
	s.push_back(v);
	instack[v] = 1;
	for (int u : adj[v]) {
		if (instack[u]) {
			low[v] = min(low[v], num[u]);
		}
		else if (num[u] == 0) {
			tarjan(u);
			low[v] = min(low[v], low[u]);
		}
	}
	if (low[v] == num[v]) {
		while (true) {
			int u = s.back();
			s.pop_back();
			instack[u] = 0;
			comp[u] = comps;
			if (u == v)
				break;
		}
		comps++;
	}
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int a;
		scanf("%d", &a);
		a--;
		forced[a] = 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		string s;
		cin >> s >> a >> b;
		a--, b--;
		if (s == "FRIENDS") {
			adj[2 * a].push_back(2 * b);
			adj[2 * b].push_back(2 * a);
			adj[2 * a + 1].push_back(2 * b + 1);
			adj[2 * b + 1].push_back(2 * a + 1);
		}
		else if (s == "ENEMIES") {
			adj[2 * a].push_back(2 * b + 1);
			adj[2 * b].push_back(2 * a + 1);
		}
		else if (s == "PARTNERS") {
			adj[2 * a].push_back(2 * b + 1);
			adj[2 * b].push_back(2 * a + 1);
			adj[2 * a + 1].push_back(2 * b);
			adj[2 * b + 1].push_back(2 * a);
		}
		else {
			adj[2 * a + 1].push_back(2 * b);
			adj[2 * b + 1].push_back(2 * a);
		}
	}

	for (int i = 0; i < 2 * n; i++)
		if (num[i] == 0)
			tarjan(i);

	for (int i = 0; i < 2 * n; i++)
		for (int j : adj[i])
			adj2[comp[i]].push_back(comp[j]);
	for (int i = 0; i < comps; i++) {
		sort(adj2[i].begin(), adj2[i].end());
		auto newend = unique(adj2[i].begin(), adj2[i].end());
		adj2[i].erase(newend, adj2[i].end());
	}

	for (int i = 0; i < comps; i++) {
		closure[i].set(i);
		for (int j : adj2[i])
			closure[i] |= closure[j];
	}
	for (int i = 0; i < n; i++)
		if (forced[i])
			force |= closure[comp[2 * i]];

	memset(ans, -1, sizeof ans);
	for (int i = 0; i < n; i++) {
		int a = comp[2 * i], b = comp[2 * i + 1];
        if (force[a] && force[b] || a == b) {
			printf("NO\n");
			return 0;
		}
		if (force[a])
			ans[i] = 1;
		if (force[b])
			ans[i] = 0;
		if (closure[a][b])
			ans[i] = 0;
		if (closure[b][a])
			ans[i] = 1;
	}
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1)
			printf("?");
		else
			printf("%d", ans[i]);
	}
	printf("\n");
}