#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define pi pair<int,int>
using namespace std;

bool up[50004];
vector<int> good[50004];
vector<pi> adj[50004];
int parent[50004];
bool allbad = false;

bool cmp(pi a, pi b) { return a.second < b.second; }

void dfs(int v) {
	set<int> children;
	int c;
	for (pi &p : adj[v]) {
		int u = p.first;
		children.insert(u);
		if (u == parent[v]) {
			c = p.second;
			continue;
		}
		parent[u] = v;
		dfs(u);
		if (up[u]) {
			if (up[v]) {
				allbad = true;
				break;
			}
			up[v] = true;
			good[v] = good[u];
		}
	}
	if (adj[v].size() > 1) {
		sort(adj[v].begin(), adj[v].end(), cmp);
		if (adj[v][0].second == adj[v][1].second)
			children.erase(adj[v][0].first);
		if (adj[v][adj[v].size() - 1].second == adj[v][adj[v].size() - 2].second)
			children.erase(adj[v][adj[v].size() - 1].first);
		for (int i = 1; i < adj[v].size() - 1; i++) {
			if (adj[v][i].second == adj[v][i - 1].second || adj[v][i].second == adj[v][i + 1].second) {
				children.erase(adj[v][i].first);
			}
		}
	}
	children.erase(parent[v]);
	for (int child : children) {
		good[v].insert(good[v].end(), good[child].begin(), good[child].end());
	}
	if (!up[v])
		good[v].push_back(v);
	if (v != 1) {
		for (pi &p : adj[v]) {
			if (p.first != parent[v] && p.second == c) {
				up[v] = true;
			}
		}
	}
}

int main()
{
	int N, a, b, c;
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back(pi(b, c));
		adj[b].push_back(pi(a, c));
	}
	dfs(1);
	if (allbad)
		printf("0");
	else {
		sort(good[1].begin(), good[1].end());
		auto last = unique(good[1].begin(), good[1].end());
		good[1].erase(last, good[1].end());
		printf("%d\n", good[1].size());
		for (int i : good[1])
			printf("%d\n", i);
	}
    return 0;
}