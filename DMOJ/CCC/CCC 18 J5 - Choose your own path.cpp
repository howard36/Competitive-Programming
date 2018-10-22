#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10004];
bool visited[10004];
vector<int> level[10004];

int main() {
	int n, m, v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &v);
			adj[i].push_back(v);
		}
	}
	level[1].push_back(1);
	visited[1] = true;
	bool foundSmallest = false;
	int smallest = -1;
	for (int i = 1; i <= n; i++) {
		if (level[i].size() == 0)
			break;
		for (int v : level[i]) {
			if (adj[v].size() == 0 && !foundSmallest) {
				smallest = i;
				foundSmallest = true;
			}
			for (int u : adj[v]) {
				if (!visited[u]) {
					visited[u] = true;
					level[i + 1].push_back(u);
				}
			}
		}
	}
	bool allVisited = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			allVisited = false;
	}
	if (allVisited) {
		printf("Y\n");
	}
	else {
		printf("N\n");
	}
	printf("%d", smallest);
}