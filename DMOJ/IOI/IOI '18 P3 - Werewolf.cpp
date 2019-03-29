#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

vi adj[200005], tree[2][200005], tour[2];
int par[2][200005], dsuPar[2][2000005], stour[2][200005], etour[2][200005];

int findDSU(int t, int a) {
	if (a == dsuPar[t][a])
		return a;
	dsuPar[t][a] = findDSU(t, dsuPar[t][a]);
	return dsuPar[t][a];
}

void join(int t, int a, int b) { // a above b in tree
	printf("join(%d, %d) called\n", a, b);
	int rep = findDSU(t, b);
	printf("findDSU(%d) = %d\n", b, rep);
	par[t][rep] = a;
	dsuPar[t][rep] = a;
}

void dfs(int t, int v) {
	stour[t][v] = tour[t].size();
	tour[t].push_back(v);
	for (int u : tree[t][v]) {
		if (u != par[t][v]) {
			dfs(t, u);
		}
	}
	etour[t][v] = tour[t].size();
	tour[t].push_back(v);
}

int main() {
	freopen("data.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	vi x, y;
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		x.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		y.push_back(temp);
	}

	// int m = x.size();
	for (int i = 0; i < m; i++) {
		adj[x[i]].push_back(y[i]);
		adj[y[i]].push_back(x[i]);
	}
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < n; i++) {
			par[t][i] = i;
			dsuPar[t][i] = i;
		}
	}

	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (adj[i][j] > i)
				break;
			join(0, i, adj[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end(), greater<int>());
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (adj[i][j] < i)
				break;
			join(1, i, adj[i][j]);
		}
	}

	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < n; i++) {
			int p = par[t][i];
			if (i != p) {
				tree[t][i].push_back(p);
				tree[t][p].push_back(i);
			}
		}
	}

	dfs(0, n-1);
    dfs(1, 0);
    
}